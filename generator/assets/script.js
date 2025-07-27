// Tab switching functionality
function switchTab(tabId, event) {
    // Prevent default behavior
    if (event) {
        event.preventDefault();
    }
    
    // Remove active class from all tabs and contents
    document.querySelectorAll('.nav-tabs .nav-link').forEach(tab => {
        tab.classList.remove('active');
        tab.setAttribute('aria-selected', 'false');
    });
    document.querySelectorAll('.tab-pane').forEach(content => {
        content.classList.remove('show', 'active');
    });
    
    // Add active class to clicked tab and corresponding content
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

// Initialize tooltips if Bootstrap is available
document.addEventListener('DOMContentLoaded', function() {
    // Initialize Bootstrap tooltips
    const tooltipTriggerList = [].slice.call(document.querySelectorAll('[data-bs-toggle="tooltip"]'));
    if (window.bootstrap && bootstrap.Tooltip) {
        tooltipTriggerList.map(function (tooltipTriggerEl) {
            return new bootstrap.Tooltip(tooltipTriggerEl);
        });
    }
    
    // Add click handlers for tabs
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

    // Improve mobile tab scrolling
    const tabContainer = document.querySelector('.nav-tabs');
    if (tabContainer && window.innerWidth <= 768) {
        const activeTab = tabContainer.querySelector('.nav-link.active');
        if (activeTab) {
            activeTab.scrollIntoView({ behavior: 'smooth', block: 'nearest', inline: 'center' });
        }
    }

    // Handle orientation change
    window.addEventListener('orientationchange', function() {
        setTimeout(() => {
            window.scrollTo(0, window.scrollY + 1);
            window.scrollTo(0, window.scrollY - 1);
        }, 100);
    });
});

// Copy code functionality
function copyCode(button) {
    const codeBlock = button.parentElement.nextElementSibling.querySelector('code');
    if (codeBlock) {
        navigator.clipboard.writeText(codeBlock.textContent).then(() => {
            const originalText = button.textContent;
            button.textContent = 'Copied!';
            button.classList.add('btn-success');
            button.classList.remove('btn-outline-secondary');
            
            setTimeout(() => {
                button.textContent = originalText;
                button.classList.remove('btn-success');
                button.classList.add('btn-outline-secondary');
            }, 2000);
        });
    }
}
