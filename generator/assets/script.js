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
