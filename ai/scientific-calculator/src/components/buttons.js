const buttons = [
    { id: 'btn7', value: '7' },
    { id: 'btn8', value: '8' },
    { id: 'btn9', value: '9' },
    { id: 'btnDivide', value: '/' },
    { id: 'btn4', value: '4' },
    { id: 'btn5', value: '5' },
    { id: 'btn6', value: '6' },
    { id: 'btnMultiply', value: '*' },
    { id: 'btn1', value: '1' },
    { id: 'btn2', value: '2' },
    { id: 'btn3', value: '3' },
    { id: 'btnSubtract', value: '-' },
    { id: 'btn0', value: '0' },
    { id: 'btnDecimal', value: '.' },
    { id: 'btnEqual', value: '=' },
    { id: 'btnAdd', value: '+' },
    { id: 'btnSin', value: 'sin' },
    { id: 'btnCos', value: 'cos' },
    { id: 'btnTan', value: 'tan' },
    { id: 'btnLog', value: 'log' },
    { id: 'btnExp', value: 'exp' },
    { id: 'btnSqrt', value: '√' },
    { id: 'btnMemAdd', value: 'M+' },
    { id: 'btnMemSubtract', value: 'M-' },
    { id: 'btnMemRecall', value: 'MR' },
    { id: 'btnMemClear', value: 'MC' },
    { id: 'btnClear', value: 'C' },
    { id: 'btnHistory', value: 'History' },
];

function createButton(button) {
    const btn = document.createElement('button');
    btn.id = button.id;
    btn.innerText = button.value;
    btn.classList.add('calculator-button');
    btn.addEventListener('click', () => handleButtonClick(button.value));
    return btn;
}

function renderButtons(container) {
    buttons.forEach(button => {
        const btn = createButton(button);
        container.appendChild(btn);
    });
}

function handleButtonClick(value) {
    // Implement button click handling logic here
}

export { renderButtons };