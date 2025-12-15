// Automated test cases for the scientific calculator UI

function simulateClick(selector, text = null) {
    const btns = Array.from(document.querySelectorAll(selector));
    let btn;
    if (text !== null) {
        btn = btns.find(b => b.textContent.trim() === text);
    } else {
        btn = btns[0];
    }
    if (btn) btn.click();
}

function setDisplay(value) {
    document.getElementById('display').textContent = value;
}

function getDisplay() {
    return document.getElementById('display').textContent;
}

function clearMemory() {
    simulateClick('#memory-clear');
}

function runCalculatorTests() {
    let passed = 0;
    let failed = 0;

    function assertEqual(actual, expected, msg) {
        if (actual === expected) {
            console.log('✅', msg);
            passed++;
        } else {
            console.error(`❌ ${msg} (expected: "${expected}", got: "${actual}")`);
            failed++;
        }
    }

    // Test 1: Basic addition
    setDisplay('');
    simulateClick('.keypad-btn', '2');
    simulateClick('.keypad-btn', '+');
    simulateClick('.keypad-btn', '3');
    simulateClick('.keypad-btn', '=');
    assertEqual(getDisplay(), '5', 'Addition: 2+3=5');

    // Test 2: Basic subtraction
    setDisplay('');
    simulateClick('.keypad-btn', '9');
    simulateClick('.keypad-btn', '-');
    simulateClick('.keypad-btn', '4');
    simulateClick('.keypad-btn', '=');
    assertEqual(getDisplay(), '5', 'Subtraction: 9-4=5');

    // Test 3: Multiplication
    setDisplay('');
    simulateClick('.keypad-btn', '6');
    simulateClick('.keypad-btn', 'x');
    simulateClick('.keypad-btn', '7');
    simulateClick('.keypad-btn', '=');
    assertEqual(getDisplay(), '42', 'Multiplication: 6*7=42');

    // Test 4: Division
    setDisplay('');
    simulateClick('.keypad-btn', '8');
    simulateClick('.keypad-btn', '/');
    simulateClick('.keypad-btn', '2');
    simulateClick('.keypad-btn', '=');
    assertEqual(getDisplay(), '4', 'Division: 8/2=4');

    // Test 5: Decimal calculation
    setDisplay('');
    simulateClick('.keypad-btn', '1');
    simulateClick('.keypad-btn', '.');
    simulateClick('.keypad-btn', '5');
    simulateClick('.keypad-btn', '+');
    simulateClick('.keypad-btn', '2');
    simulateClick('.keypad-btn', '.');
    simulateClick('.keypad-btn', '5');
    simulateClick('.keypad-btn', '=');
    assertEqual(getDisplay(), '4', 'Decimal: 1.5+2.5=4');

    // Test 6: Clear key
    setDisplay('12345');
    simulateClick('.keypad-btn', 'C');
    assertEqual(getDisplay(), '', 'Clear key resets display');

    // Test 7: Memory add and recall
    clearMemory();
    setDisplay('10');
    simulateClick('#memory-add');
    setDisplay('5');
    simulateClick('#memory-add');
    simulateClick('#memory-recall');
    assertEqual(getDisplay(), '15', 'Memory add and recall');

    // Test 8: Memory subtract and recall
    clearMemory();
    setDisplay('20');
    simulateClick('#memory-add');
    setDisplay('7');
    simulateClick('#memory-subtract');
    simulateClick('#memory-recall');
    assertEqual(getDisplay(), '13', 'Memory subtract and recall');

    // Test 9: Memory clear
    clearMemory();
    setDisplay('8');
    simulateClick('#memory-add');
    simulateClick('#memory-clear');
    simulateClick('#memory-recall');
    assertEqual(getDisplay(), '', 'Memory clear');

    // Test 10: Invalid expression
    setDisplay('2++2');
    simulateClick('.keypad-btn', '=');
    assertEqual(getDisplay(), 'Error', 'Invalid expression shows Error');

    // Summary
    console.log(`\nTest summary: ${passed} passed, ${failed} failed`);
}

// Run tests after DOM is loaded
if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', runCalculatorTests);
} else {
    runCalculatorTests();
}
