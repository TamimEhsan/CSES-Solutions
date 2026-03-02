// Tab switching functionality for custom tabs
function switchCustomTab(tabId, clickedElement) {
    // Remove active class from all custom tabs and contents
    document.querySelectorAll('.nav-link-custom').forEach(tab => {
        tab.classList.remove('active');
        tab.setAttribute('aria-selected', 'false');
    });
    document.querySelectorAll('.tab-pane').forEach(content => {
        content.classList.remove('show', 'active');
    });
    
    // Add active class to clicked tab and corresponding content
    if (clickedElement) {
        clickedElement.classList.add('active');
        clickedElement.setAttribute('aria-selected', 'true');
    }
    
    const targetContent = document.getElementById(tabId);
    if (targetContent) {
        targetContent.classList.add('show', 'active');
    }
}

// Tab switching functionality (legacy support)
function switchTab(tabId, event) {
    // Prevent default behavior
    if (event) {
        event.preventDefault();
    }
    
    // Handle both custom and standard tabs
    const isCustomTab = event && event.target.classList.contains('nav-link-custom');
    
    if (isCustomTab) {
        switchCustomTab(tabId, event.target);
        return;
    }
    
    // Legacy tab handling
    document.querySelectorAll('.nav-tabs .nav-link').forEach(tab => {
        tab.classList.remove('active');
        tab.setAttribute('aria-selected', 'false');
    });
    document.querySelectorAll('.tab-pane').forEach(content => {
        content.classList.remove('show', 'active');
    });
    
    const clickedTab = event ? event.target : document.querySelector(`[data-bs-target="#${tabId}"]`);
    if (clickedTab) {
        clickedTab.classList.add('active');
        clickedTab.setAttribute('aria-selected', 'true');
    }
    
    const targetContent = document.getElementById(tabId);
    if (targetContent) {
        targetContent.classList.add('show', 'active');
    }
}

// Initialize tab functionality
document.addEventListener('DOMContentLoaded', function() {
    // Initialize Bootstrap tooltips
    const tooltipTriggerList = [].slice.call(document.querySelectorAll('[data-bs-toggle="tooltip"]'));
    if (window.bootstrap && bootstrap.Tooltip) {
        tooltipTriggerList.map(function (tooltipTriggerEl) {
            return new bootstrap.Tooltip(tooltipTriggerEl);
        });
    }

    // Add click handlers for custom tabs
    document.querySelectorAll('.nav-link-custom').forEach(tab => {
        tab.addEventListener('click', function(e) {
            e.preventDefault();
            const target = this.getAttribute('data-bs-target');
            if (target) {
                const tabId = target.replace('#', '');
                switchCustomTab(tabId, this);
            }
        });
    });
    
    // Add click handlers for standard tabs (legacy support)
    document.querySelectorAll('.nav-tabs .nav-link').forEach(tab => {
        tab.addEventListener('click', function(e) {
            e.preventDefault();
            const target = this.getAttribute('data-bs-target');
            if (target) {
                const tabId = target.replace('#', '');
                switchTab(tabId, e);
            }
        });
    });

    // Initialize tab scroll gradients
    const tabScrollContainer = document.getElementById('problemTabsScroll');
    const tabWrapper = document.querySelector('.tab-nav-wrapper');
    
    if (tabScrollContainer && tabWrapper) {
        function updateTabScrollGradients() {
            const { scrollLeft, scrollWidth, clientWidth } = tabScrollContainer;
            const hasOverflow = scrollWidth > clientWidth;
            
            if (hasOverflow) {
                if (scrollLeft > 10) {
                    tabWrapper.classList.add('show-left');
                } else {
                    tabWrapper.classList.remove('show-left');
                }
                
                if (scrollLeft < scrollWidth - clientWidth - 10) {
                    tabWrapper.classList.add('show-right');
                } else {
                    tabWrapper.classList.remove('show-right');
                }
            } else {
                tabWrapper.classList.remove('show-left', 'show-right');
            }
        }
        
        tabScrollContainer.addEventListener('scroll', updateTabScrollGradients);
        window.addEventListener('resize', updateTabScrollGradients);
        updateTabScrollGradients();
    }
});

// Copy code functionality
function copyCode(button) {
    const container = button.closest('[data-filename]') || button.parentElement.parentElement;
    const codeBlock = container.querySelector('code');
    if (codeBlock) {
        navigator.clipboard.writeText(codeBlock.textContent).then(() => {
            const originalHTML = button.innerHTML;
            button.innerHTML = '<i class="fas fa-check me-1"></i>Copied!';
            button.classList.add('btn-success');
            button.classList.remove('btn-outline-secondary');

            setTimeout(() => {
                button.innerHTML = originalHTML;
                button.classList.remove('btn-success');
                button.classList.add('btn-outline-secondary');
            }, 2000);
        });
    }
}

// Download code functionality
function downloadCode(button) {
    const container = button.closest('[data-filename]');
    const codeBlock = container.querySelector('code');
    const filename = container.getAttribute('data-filename');

    if (codeBlock && filename) {
        const code = codeBlock.textContent;
        const blob = new Blob([code], { type: 'text/plain' });
        const url = URL.createObjectURL(blob);
        const a = document.createElement('a');
        a.href = url;
        a.download = filename;
        document.body.appendChild(a);
        a.click();
        document.body.removeChild(a);
        URL.revokeObjectURL(url);

        // Visual feedback
        const originalHTML = button.innerHTML;
        button.innerHTML = '<i class="fas fa-check me-1"></i>Downloaded!';
        button.classList.add('btn-success');
        button.classList.remove('btn-outline-secondary');

        setTimeout(() => {
            button.innerHTML = originalHTML;
            button.classList.remove('btn-success');
            button.classList.add('btn-outline-secondary');
        }, 2000);
    }
}

// Language switcher functionality
function switchLanguage(langId, button) {
    // Hide all language content blocks
    document.querySelectorAll('.lang-content').forEach(content => {
        content.classList.add('d-none');
    });

    // Remove active class from all language buttons
    document.querySelectorAll('.lang-btn').forEach(btn => {
        btn.classList.remove('active');
    });

    // Show selected language content
    const targetContent = document.getElementById('lang-' + langId);
    if (targetContent) {
        targetContent.classList.remove('d-none');
    }

    // Add active class to clicked button
    if (button) {
        button.classList.add('active');
    }
}

// Back to Top Button Functionality
window.addEventListener('load', function() {
    const backToTopButton = document.getElementById('backToTop');

    if (backToTopButton) {
        // Show/hide button based on scroll position
        window.addEventListener('scroll', function() {
            if (window.pageYOffset > 300) {
                backToTopButton.classList.add('show');
            } else {
                backToTopButton.classList.remove('show');
            }
        });

        // Scroll to top when clicked
        backToTopButton.addEventListener('click', function() {
            window.scrollTo({
                top: 0,
                behavior: 'smooth'
            });
        });
    }
});
