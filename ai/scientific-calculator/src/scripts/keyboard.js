document.addEventListener('keydown', function(event) {
    const key = event.key;

    // Prevent default behavior for certain keys
    if (key === 'Enter') {
        event.preventDefault();
        // Trigger calculation
        calculate();
    } else if (key === 'Backspace') {
        event.preventDefault();
        // Handle backspace
        deleteLastCharacter();
    } else if (key === 'Escape') {
        event.preventDefault();
        // Clear the display
        clearDisplay();
    } else if (key === 'm') {
        // Memory operations
        handleMemoryOperations();
    } else {
        // Map other keys to calculator buttons
        const button = document.querySelector(`button[data-key="${key}"]`);
        if (button) {
            button.click();
        }
    }
});

function calculate() {
    // Implementation for calculation logic
}

function deleteLastCharacter() {
    // Implementation for deleting last character in display
}

function clearDisplay() {
    // Implementation for clearing the display
}

function handleMemoryOperations() {
    // Implementation for memory operations (M+, M-, MR, MC)
}