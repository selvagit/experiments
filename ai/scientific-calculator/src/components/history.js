const historyContainer = document.createElement('div');
historyContainer.className = 'history-container';

const historyList = document.createElement('ul');
historyList.className = 'history-list';

const clearHistoryButton = document.createElement('button');
clearHistoryButton.innerText = 'Clear History';
clearHistoryButton.className = 'clear-history-button';

let calculationHistory = [];

function addToHistory(calculation) {
    calculationHistory.push(calculation);
    updateHistoryDisplay();
}

function updateHistoryDisplay() {
    historyList.innerHTML = '';
    calculationHistory.forEach((calc, index) => {
        const listItem = document.createElement('li');
        listItem.innerText = `${index + 1}: ${calc}`;
        historyList.appendChild(listItem);
    });
}

function clearHistory() {
    calculationHistory = [];
    updateHistoryDisplay();
}

clearHistoryButton.addEventListener('click', clearHistory);

historyContainer.appendChild(historyList);
historyContainer.appendChild(clearHistoryButton);

export { historyContainer, addToHistory };