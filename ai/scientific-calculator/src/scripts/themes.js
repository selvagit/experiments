const themes = {
    classic: {
        backgroundColor: '#ffffff',
        color: '#000000',
        buttonBackground: '#e0e0e0',
        buttonColor: '#000000',
        buttonHover: '#d0d0d0',
    },
    modern: {
        backgroundColor: '#282c34',
        color: '#ffffff',
        buttonBackground: '#61dafb',
        buttonColor: '#282c34',
        buttonHover: '#21a1f1',
    },
    highContrast: {
        backgroundColor: '#000000',
        color: '#ffffff',
        buttonBackground: '#ffcc00',
        buttonColor: '#000000',
        buttonHover: '#e6b800',
    }
};

let currentTheme = 'classic';

function applyTheme(theme) {
    const root = document.documentElement;
    const selectedTheme = themes[theme];

    if (selectedTheme) {
        root.style.setProperty('--background-color', selectedTheme.backgroundColor);
        root.style.setProperty('--text-color', selectedTheme.color);
        root.style.setProperty('--button-background', selectedTheme.buttonBackground);
        root.style.setProperty('--button-color', selectedTheme.buttonColor);
        root.style.setProperty('--button-hover', selectedTheme.buttonHover);
        currentTheme = theme;
    }
}

function toggleTheme() {
    const nextTheme = currentTheme === 'classic' ? 'modern' : currentTheme === 'modern' ? 'highContrast' : 'classic';
    applyTheme(nextTheme);
}

document.addEventListener('DOMContentLoaded', () => {
    applyTheme(currentTheme);
    const themeToggleButton = document.getElementById('theme-toggle');
    if (themeToggleButton) {
        themeToggleButton.addEventListener('click', toggleTheme);
    }
});