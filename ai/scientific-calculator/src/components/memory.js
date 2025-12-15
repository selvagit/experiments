const memory = {
    value: 0,
    displayElement: null,

    init(displayElement) {
        this.displayElement = displayElement;
        this.updateDisplay();
    },

    memoryAdd(number) {
        this.value += number;
        this.updateDisplay();
    },

    memorySubtract(number) {
        this.value -= number;
        this.updateDisplay();
    },

    memoryRecall() {
        return this.value;
    },

    memoryClear() {
        this.value = 0;
        this.updateDisplay();
    },

    updateDisplay() {
        if (this.displayElement) {
            this.displayElement.textContent = `Memory: ${this.value}`;
        }
    }
};

export default memory;