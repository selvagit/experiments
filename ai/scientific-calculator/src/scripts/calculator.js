const calculator = {
    displayValue: '0',
    firstOperand: null,
    secondOperand: null,
    operator: null,
    waitingForSecondOperand: false,
    memory: 0,
    history: [],
    isDegree: true,

    inputDigit(digit) {
        if (this.waitingForSecondOperand) {
            this.displayValue = digit;
            this.waitingForSecondOperand = false;
        } else {
            this.displayValue = this.displayValue === '0' ? digit : this.displayValue + digit;
        }
        this.updateDisplay();
    },

    inputOperator(operator) {
        const { firstOperand, secondOperand, waitingForSecondOperand } = this;

        if (this.operator && waitingForSecondOperand) {
            this.operator = operator;
            return;
        }

        if (firstOperand === null && !isNaN(this.displayValue)) {
            this.firstOperand = parseFloat(this.displayValue);
        } else if (this.operator) {
            const result = this.performCalculation(this.operator, firstOperand, parseFloat(this.displayValue));
            this.displayValue = String(result);
            this.firstOperand = result;
        }

        this.operator = operator;
        this.waitingForSecondOperand = true;
        this.history.push(this.displayValue);
        this.updateDisplay();
    },

    performCalculation(operator, firstOperand, secondOperand) {
        switch (operator) {
            case '+':
                return firstOperand + secondOperand;
            case '-':
                return firstOperand - secondOperand;
            case '*':
                return firstOperand * secondOperand;
            case '/':
                if (secondOperand === 0) {
                    this.displayError('Division by zero');
                    return firstOperand;
                }
                return firstOperand / secondOperand;
            case 'sin':
                return this.isDegree ? Math.sin(this.toRadians(firstOperand)) : Math.sin(firstOperand);
            case 'cos':
                return this.isDegree ? Math.cos(this.toRadians(firstOperand)) : Math.cos(firstOperand);
            case 'tan':
                return this.isDegree ? Math.tan(this.toRadians(firstOperand)) : Math.tan(firstOperand);
            case 'log':
                return Math.log10(firstOperand);
            case 'ln':
                return Math.log(firstOperand);
            case 'exp':
                return Math.exp(firstOperand);
            default:
                return secondOperand;
        }
    },

    toRadians(degrees) {
        return degrees * (Math.PI / 180);
    },

    toggleDegreeRadian() {
        this.isDegree = !this.isDegree;
    },

    memoryAdd() {
        this.memory += parseFloat(this.displayValue);
    },

    memorySubtract() {
        this.memory -= parseFloat(this.displayValue);
    },

    memoryRecall() {
        this.displayValue = String(this.memory);
        this.updateDisplay();
    },

    memoryClear() {
        this.memory = 0;
    },

    updateDisplay() {
        const display = document.querySelector('.calculator-display');
        display.value = this.displayValue;
    },

    displayError(message) {
        this.displayValue = message;
        this.updateDisplay();
        setTimeout(() => {
            this.displayValue = '0';
            this.updateDisplay();
        }, 2000);
    },

    clear() {
        this.displayValue = '0';
        this.firstOperand = null;
        this.secondOperand = null;
        this.operator = null;
        this.waitingForSecondOperand = false;
        this.updateDisplay();
    },

    toggleSound() {
        // Implement sound toggle functionality
    },

    copyToClipboard() {
        navigator.clipboard.writeText(this.displayValue);
    },

    pasteFromClipboard() {
        navigator.clipboard.readText().then(text => {
            this.displayValue = text;
            this.updateDisplay();
        });
    }
};

document.querySelectorAll('.calculator-button').forEach(button => {
    button.addEventListener('click', () => {
        const value = button.dataset.value;
        if (!isNaN(value)) {
            calculator.inputDigit(value);
        } else if (value === 'C') {
            calculator.clear();
        } else if (value === '=') {
            calculator.inputOperator(calculator.operator);
        } else {
            calculator.inputOperator(value);
        }
    });
});