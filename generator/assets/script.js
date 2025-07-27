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

    // Enhanced tab navigation
    initializeTabNavigation();

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

// Enhanced tab navigation functionality
function initializeTabNavigation() {
    const tabContainer = document.getElementById('problemTabsScroll');
    const tabWrapper = document.querySelector('.tab-nav-wrapper');
    
    if (!tabContainer || !tabWrapper) return;

    // Add scroll indicators
    function updateScrollIndicators() {
        const { scrollLeft, scrollWidth, clientWidth } = tabContainer;
        const isScrollable = scrollWidth > clientWidth;
        
        if (isScrollable) {
            tabWrapper.classList.toggle('show-left', scrollLeft > 10);
            tabWrapper.classList.toggle('show-right', scrollLeft < scrollWidth - clientWidth - 10);
        } else {
            tabWrapper.classList.remove('show-left', 'show-right');
        }
    }

    // Initialize scroll indicators
    updateScrollIndicators();
    
    // Update indicators on scroll
    tabContainer.addEventListener('scroll', updateScrollIndicators);
    
    // Update indicators on resize
    window.addEventListener('resize', updateScrollIndicators);

    // Enhanced tab switching with smooth scrolling
    document.querySelectorAll('.nav-link-custom').forEach(tab => {
        tab.addEventListener('click', function(e) {
            e.preventDefault();
            const target = this.getAttribute('data-bs-target');
            if (target) {
                const tabId = target.replace('#', '');
                switchTabEnhanced(tabId, e);
                scrollTabIntoView(this);
            }
        });
    });

    // Scroll active tab into view
    const activeTab = tabContainer.querySelector('.nav-link-custom.active');
    if (activeTab) {
        setTimeout(() => scrollTabIntoView(activeTab), 100);
    }
}

// Enhanced tab switching function
function switchTabEnhanced(tabId, event) {
    // Prevent default behavior
    if (event) {
        event.preventDefault();
    }
    
    // Remove active class from all tabs and contents
    document.querySelectorAll('.nav-link-custom').forEach(tab => {
        tab.classList.remove('active');
        tab.setAttribute('aria-selected', 'false');
    });
    document.querySelectorAll('.tab-pane').forEach(content => {
        content.classList.remove('show', 'active');
    });
    
    // Add active class to clicked tab and corresponding content
    const clickedTab = event ? event.target.closest('.nav-link-custom') : 
                      document.querySelector(`[data-bs-target="#${tabId}"]`);
    if (clickedTab) {
        clickedTab.classList.add('active');
        clickedTab.setAttribute('aria-selected', 'true');
    }
    
    const targetContent = document.getElementById(tabId);
    if (targetContent) {
        targetContent.classList.add('show', 'active');
    }
}

// Scroll tab into view smoothly
function scrollTabIntoView(tab) {
    const container = document.getElementById('problemTabsScroll');
    if (!container || !tab) return;
    
    const containerRect = container.getBoundingClientRect();
    const tabRect = tab.getBoundingClientRect();
    
    const scrollLeft = container.scrollLeft;
    const targetScroll = scrollLeft + (tabRect.left - containerRect.left) - 
                        (containerRect.width - tabRect.width) / 2;
    
    container.scrollTo({
        left: Math.max(0, targetScroll),
        behavior: 'smooth'
    });
}

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
