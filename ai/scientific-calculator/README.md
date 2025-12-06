# Scientific Calculator

This project is a comprehensive scientific calculator built with HTML5, CSS3, and JavaScript. It mimics the functionality of professional calculators and includes a variety of features to enhance user experience.

## Features

- **Basic Arithmetic Operations**: Supports addition, subtraction, multiplication, and division with proper order of operations.
- **Advanced Scientific Functions**: Includes trigonometric (sin, cos, tan), logarithmic (log, ln), exponential (exp), and statistical functions.
- **Degree/Radian Toggle**: Easily switch between degree and radian modes for trigonometric calculations.
- **Memory Operations**: Memory functions (M+, M-, MR, MC) with visual indicators to track memory status.
- **Calculation History Log**: A scrollable log that displays past calculations, which can be cleared or saved.
- **Full Keyboard Support**: Supports keyboard input with appropriate key mappings and shortcuts for all calculator functions.
- **Error Handling**: Robust error handling for division by zero, invalid operations, and overflow conditions, with helpful error messages.
- **Responsive Design**: Adapts between standard and scientific layouts based on screen size or orientation.
- **Multiple Theme Options**: Choose from classic, modern, and high contrast themes to suit user preferences.
- **Sound Feedback**: Optional sound effects for button presses, with volume control for user convenience.
- **Copy/Paste Functionality**: Easily copy results and expressions for use in other applications.

## Installation

1. Clone the repository:
   
   ```bash
   git clone https://github.com/yourusername/scientific-calculator.git
   ```

2. Navigate to the project directory:

   ```bash
   cd scientific-calculator
   ```

3. Open `src/index.html` in your web browser to use the calculator.

## Usage

- Use the buttons or keyboard shortcuts to perform calculations.
- Toggle between themes using the theme switcher in the interface.
- Access the calculation history to review past entries.
- Utilize memory functions to store and recall values.

## Running Calculator Test Cases

To run the automated test cases for your scientific calculator UI, open the following URL in your browser (assuming you're using a local development environment like VS Code's "Live Server" or similar):

```
http://localhost:5500/workspaces/experiments/ai/scientific-calculator/src/index.html
```

- Make sure `calculator.test.js` is included in your `index.html` (add `<script src="calculator.test.js"></script>` at the end of the `<body>` if not already present).

---

## Calculator Logic: Multiplication and Division

The calculator supports multiplication and division using the following logic:

- **Multiplication**: Use the `*` button or key to multiply two numbers.  
  Example: `6 * 7 = 42`

- **Division**: Use the `/` button or key to divide one number by another.  
  Example: `8 / 2 = 4`

Internally, when you press the multiplication (`×`) or division (`÷`) buttons, the calculator converts these symbols to `*` and `/` for evaluation in JavaScript. This ensures correct calculation results for all multiplication and division operations.

---

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue for any suggestions or improvements.

## License

This project is licensed under the MIT License. See the LICENSE file for details.