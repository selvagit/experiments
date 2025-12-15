function handleDivisionByZero() {
    return "Error: Division by zero";
}

function handleInvalidOperation() {
    return "Error: Invalid operation";
}

function handleOverflow() {
    return "Error: Overflow";
}

function isNumber(value) {
    return typeof value === 'number' && isFinite(value);
}

function validateInput(value) {
    if (!isNumber(value)) {
        throw new Error(handleInvalidOperation());
    }
}

function safeDivide(a, b) {
    validateInput(a);
    validateInput(b);
    if (b === 0) {
        return handleDivisionByZero();
    }
    return a / b;
}

function safeAdd(a, b) {
    validateInput(a);
    validateInput(b);
    const result = a + b;
    if (!isNumber(result)) {
        return handleOverflow();
    }
    return result;
}

function safeSubtract(a, b) {
    validateInput(a);
    validateInput(b);
    const result = a - b;
    if (!isNumber(result)) {
        return handleOverflow();
    }
    return result;
}

function safeMultiply(a, b) {
    validateInput(a);
    validateInput(b);
    const result = a * b;
    if (!isNumber(result)) {
        return handleOverflow();
    }
    return result;
}

function safeExponentiate(base, exponent) {
    validateInput(base);
    validateInput(exponent);
    const result = Math.pow(base, exponent);
    if (!isNumber(result)) {
        return handleOverflow();
    }
    return result;
}

function safeLogarithm(value, base = Math.E) {
    validateInput(value);
    if (value <= 0) {
        return "Error: Logarithm of non-positive number";
    }
    return Math.log(value) / Math.log(base);
}

function toggleDegreesRadians(isDegrees) {
    return isDegrees ? "Degrees" : "Radians";
}

export {
    safeDivide,
    safeAdd,
    safeSubtract,
    safeMultiply,
    safeExponentiate,
    safeLogarithm,
    toggleDegreesRadians
};