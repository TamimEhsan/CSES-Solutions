const fs = require('fs');
const path = require('path');
const ejs = require('ejs');

class CSESStaticGenerator {
    constructor(options = {}) {
        this.basePath = options.basePath || 'generator';
        this.dataPath = options.dataPath || 'data.json';
        this.dataPath = path.join(this.basePath, this.dataPath);
        this.topicsPath = options.topicsPath || './topics';
        this.topicsPath = path.join(this.basePath, this.topicsPath);
        this.outputPath = options.outputPath || './dist';
        // this.outputPath = path.join(this.basePath, this.outputPath);
        this.templatesPath = options.templatesPath || 'templates';
        this.templatesPath = path.join(this.basePath, this.templatesPath);
        this.assetsPath = options.assetsPath || 'assets';
        this.assetsPath = path.join(this.basePath, this.assetsPath);
        this.baseUrl = options.baseUrl || '';
        
        this.data = null;
        this.templates = {};
        this.marked = null;
    }

    async init() {
        // Load marked module
        const markedModule = await import('marked');
        this.marked = markedModule.marked;
        
        // Create output directory if it doesn't exist
        if (!fs.existsSync(this.outputPath)) {
            fs.mkdirSync(this.outputPath, { recursive: true });
        }
        
        // Load data
        this.loadData();
        
        // Load templates
        this.loadTemplates();
        
        // Generate site
        this.generateSite();
    }

    loadData() {
        try {
            const dataContent = fs.readFileSync(this.dataPath, 'utf8');
            this.data = JSON.parse(dataContent);
            
            // Check solved status based on file existence
            this.checkSolvedStatus();
            
            console.log(`✓ Loaded data with ${this.data.topics.length} topics`);
        } catch (error) {
            console.error('Error loading data:', error.message);
            process.exit(1);
        }
    }

    checkSolvedStatus() {
        this.data.topics.forEach(topic => {
            topic.problems.forEach(problem => {
                const problemPath = path.join(this.topicsPath, topic.id, problem.id);
                const solutionPath = path.join(topic.name, "");
                
                // Check if code files exist
                const cppPath = path.join(solutionPath, `${problem.name}.cpp`);
                const javaPath = path.join(solutionPath, `${problem.name}.java`);
                const pythonPath = path.join(solutionPath, `${problem.name}.py`);
                
                problem.solved = fs.existsSync(cppPath) || fs.existsSync(javaPath) || fs.existsSync(pythonPath);
                problem.hasHints = fs.existsSync(path.join(problemPath, 'hints.md'));
                problem.hasSolution = fs.existsSync(path.join(problemPath, 'solution.md'));
                problem.hasDescription = fs.existsSync(path.join(problemPath, 'description.md'));
                
                // console.log(`Problem ${problem.id} (${problem.name}) in (${problemPath} and ${solutionPath}) solved status: ${problem.solved}`);
                // console.log(`  - Hints available: ${problem.hasHints}`);
                // console.log(`  - Solution available: ${problem.hasSolution}`);
                // console.log(`  - Description available: ${problem.hasDescription}`);


                // Available code languages
                problem.codeLanguages = [];
                if (fs.existsSync(cppPath)) problem.codeLanguages.push({ name: 'C++', file: `${problem.name}.cpp`, lang: 'cpp' });
                if (fs.existsSync(javaPath)) problem.codeLanguages.push({ name: 'Java', file: `${problem.name}.java`, lang: 'java' });
                if (fs.existsSync(pythonPath)) problem.codeLanguages.push({ name: 'Python', file: `${problem.name}.py`, lang: 'python' });
            });
        });
    }

    loadTemplates() {
        const templateFiles = ['base.ejs', 'home.ejs', 'topic.ejs', 'problem.ejs'];
        
        templateFiles.forEach(file => {
            try {
                const templatePath = path.join(this.templatesPath, file);
                const templateName = path.basename(file, '.ejs');
                this.templates[templateName] = fs.readFileSync(templatePath, 'utf8');
                console.log(`✓ Loaded template: ${templateName}`);
            } catch (error) {
                console.error(`Error loading template ${file}:`, error.message);
                process.exit(1);
            }
        });
    }

    generateSite() {
        console.log('🚀 Generating static site...\n');
        
        // Generate home page
        this.generateHomePage();
        
        // Generate topic pages
        this.data.topics.forEach(topic => {
            this.generateTopicPage(topic);
            
            // Generate problem pages
            topic.problems.forEach(problem => {
                this.generateProblemPage(topic, problem);
            });
        });
        
        // Copy static assets
        this.copyStaticAssets();
        
        console.log(`\n✅ Site generated successfully in ${this.outputPath}`);
        this.printSummary();
    }

    generateHomePage() {
        const topicsWithStats = this.data.topics.map(topic => {
            const totalProblems = topic.problems.length;
            const solvedProblems = topic.problems.filter(p => p.solved).length;
            const progress = totalProblems > 0 ? (solvedProblems / totalProblems) * 100 : 0;
            
            return {
                ...topic,
                totalProblems,
                solvedProblems,
                progress: Math.round(progress)
            };
        });

        const stats = {
            totalTopics: this.data.topics.length,
            totalProblems: this.data.topics.reduce((sum, t) => sum + t.problems.length, 0),
            totalSolved: this.data.topics.reduce((sum, t) => sum + t.problems.filter(p => p.solved).length, 0)
        };

        const content = ejs.render(this.templates.home, {
            topics: topicsWithStats,
            stats
        });

        const html = ejs.render(this.templates.base, {
            title: 'CSES Solutions - Competitive Programming Practice',
            description: 'Comprehensive solutions and explanations for CSES Problem Set - competitive programming practice problems with detailed analysis.',
            keywords: 'CSES, competitive programming, algorithms, data structures, programming solutions, CSES Problem Set, CSES solutions, CSES practice problems',
            breadcrumb: '<li class="breadcrumb-item active">Home</li>',
            content,
            cssPath: 'style.css',
            jsPath: 'script.js',
            homePath: 'index.html'
        });

        fs.writeFileSync(path.join(this.outputPath, 'index.html'), html);
        console.log('✓ Generated home page');
    }

    generateTopicPage(topic) {
        const topicDir = path.join(this.outputPath, topic.id);
        if (!fs.existsSync(topicDir)) {
            fs.mkdirSync(topicDir, { recursive: true });
        }

        const content = ejs.render(this.templates.topic, {
            topic,
            problems: topic.problems
        });

        const html = ejs.render(this.templates.base, {
            title: `${topic.name} - CSES Solutions`,
            description: `${topic.name} problems from CSES Problem Set with detailed solutions and explanations.`,
            keywords: `CSES, competitive programming, algorithms, data structures, programming solutions, ${topic.name}, ${topic.name} problems, ${topic.name} solutions`,
            breadcrumb: `<li class="breadcrumb-item"><a href="../index.html">Home</a></li><li class="breadcrumb-item active">${topic.name}</li>`,
            content,
            cssPath: '../style.css',
            jsPath: '../script.js',
            homePath: '../index.html'
        });

        fs.writeFileSync(path.join(topicDir, 'index.html'), html);
        console.log(`✓ Generated topic page: ${topic.name}`);
    }

    generateProblemPage(topic, problem) {
        const problemDir = path.join(this.outputPath, topic.id, problem.id);
        if (!fs.existsSync(problemDir)) {
            fs.mkdirSync(problemDir, { recursive: true });
        }

        // Load problem content
        const problemContent = this.loadProblemContent(topic, problem);
        
        // Build tabs array
        const tabs = [];
        if (problemContent.description) tabs.push({ id: 'description', name: 'Description' });
        if (problemContent.hints) tabs.push({ id: 'hints', name: 'Hints' });
        if (problemContent.solution) tabs.push({ id: 'solution', name: 'Solution' });
        if (problemContent.code && Object.keys(problemContent.code).length > 0) tabs.push({ id: 'code', name: 'Code' });

        const content = ejs.render(this.templates.problem, {
            problem,
            topic,
            tabs,
            content: problemContent
        });

        const html = ejs.render(this.templates.base, {
            title: `${problem.name} - CSES Solutions`,
            description: `Solution and explanation for ${problem.name} from CSES Problem Set.`,
            keywords: `CSES, competitive programming, algorithms, data structures, programming solutions, ${problem.name}, Solution for ${problem.name}, ${problem.name} solution, ${problem.name} CSES solution`,
            breadcrumb: `<li class="breadcrumb-item"><a href="../../index.html">Home</a></li><li class="breadcrumb-item"><a href="../index.html">${topic.name}</a></li><li class="breadcrumb-item active">${problem.name}</li>`,
            content,
            cssPath: '../../style.css',
            jsPath: '../../script.js',
            homePath: '../../index.html'
        });

        fs.writeFileSync(path.join(problemDir, 'index.html'), html);
        // console.log(`  ✓ Generated problem page: ${problem.name}`);
    }

    loadProblemContent(topic, problem) {
        const problemPath = path.join(this.topicsPath, topic.id, problem.id);
        const solutionPath = path.join(topic.name, "");
        const content = {};

        // Load description
        if (problem.hasDescription) {
            console.log(`Loading description for ${problem.id}...`);
            try {
                const descPath = path.join(problemPath, 'description.md');
                content.description = this.marked(fs.readFileSync(descPath, 'utf8'));
            } catch (error) {
                content.description = '<p>Description not available.</p>';
            }
        }

        // Load hints
        if (problem.hasHints) {
            try {
                const hintsPath = path.join(problemPath, 'hints.md');
                content.hints = this.marked(fs.readFileSync(hintsPath, 'utf8'));
            } catch (error) {
                content.hints = '<p>Hints not available.</p>';
            }
        }

        // Load solution
        if (problem.hasSolution) {
            try {
                const solutionPath = path.join(problemPath, 'solution.md');
                content.solution = this.marked(fs.readFileSync(solutionPath, 'utf8'));
            } catch (error) {
                content.solution = '<p>Solution not available.</p>';
            }
        }

        // Load code files
        if (problem.codeLanguages.length > 0) {
            content.code = {};
            problem.codeLanguages.forEach(lang => {
                try {
                    const codePath = path.join(solutionPath, lang.file);
                    const codeContent = fs.readFileSync(codePath, 'utf8');
                    content.code[lang.name] = {
                        content: this.escapeHtml(codeContent),
                        language: lang.lang
                    };
                } catch (error) {
                    console.warn(`Warning: Could not load ${lang.file} for ${problem.id}`);
                }
            });
        }

        return content;
    }

    escapeHtml(text) {
        const map = {
            '&': '&amp;',
            '<': '&lt;',
            '>': '&gt;',
            '"': '&quot;',
            "'": '&#039;'
        };
        return text.replace(/[&<>"']/g, m => map[m]);
    }

    copyStaticAssets() {
        // Copy CSS file
        const cssSource = path.join(this.assetsPath, 'style.css');
        const cssTarget = path.join(this.outputPath, 'style.css');
        if (fs.existsSync(cssSource)) {
            fs.copyFileSync(cssSource, cssTarget);
        }
        
        // Copy JS file
        const jsSource = path.join(this.assetsPath, 'script.js');
        const jsTarget = path.join(this.outputPath, 'script.js');
        if (fs.existsSync(jsSource)) {
            fs.copyFileSync(jsSource, jsTarget);
        }
        
        console.log('✓ Copied static assets');
    }

    printSummary() {
        const totalProblems = this.data.topics.reduce((sum, t) => sum + t.problems.length, 0);
        const totalSolved = this.data.topics.reduce((sum, t) => sum + t.problems.filter(p => p.solved).length, 0);
        
        console.log('\n📊 Site Summary:');
        console.log(`   Topics: ${this.data.topics.length}`);
        console.log(`   Problems: ${totalProblems}`);
        console.log(`   Solved: ${totalSolved}`);
        console.log(`   Progress: ${Math.round((totalSolved / totalProblems) * 100)}%`);
        console.log(`\n🌐 Site generated in: ${path.resolve(this.outputPath)}`);
    }
}

// Usage example and CLI
if (require.main === module) {
    (async () => {
        const args = process.argv.slice(2);
        const options = {};
        
        // Parse command line arguments
        for (let i = 0; i < args.length; i += 2) {
            const key = args[i].replace('--', '');
            const value = args[i + 1];
            options[key] = value;
        }
        
        console.log('🏗️  CSES Static Site Generator\n');
        
        try {
            const generator = new CSESStaticGenerator(options);
            await generator.init();
        } catch (error) {
            console.error('Error generating site:', error.message);
            process.exit(1);
        }
    })();
}

module.exports = CSESStaticGenerator;