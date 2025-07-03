class Calculator {
            constructor(previousOperandTextElement, currentOperandTextElement) {
                this.previousOperandTextElement = previousOperandTextElement;
                this.currentOperandTextElement = currentOperandTextElement;
                this.clear();
            }

            clear() {
                this.currentOperand = '';
                this.previousOperand = '';
                this.operation = undefined;
                this.shouldResetScreen = false;
            }

            delete() {
                if (this.shouldResetScreen) return;
                this.currentOperand = this.currentOperand.toString().slice(0, -1);
            }

            appendNumber(number) {
                if (this.shouldResetScreen) {
                    this.currentOperand = '';
                    this.shouldResetScreen = false;
                }
                if (number === '.' && this.currentOperand.includes('.')) return;
                this.currentOperand = this.currentOperand.toString() + number.toString();
            }

            chooseOperation(operation) {
                if (this.currentOperand === '') return;
                if (this.previousOperand !== '') {
                    this.compute();
                }
                this.operation = operation;
                this.previousOperand = this.currentOperand;
                this.currentOperand = '';
            }

            compute() {
                let computation;
                const prev = parseFloat(this.previousOperand);
                const current = parseFloat(this.currentOperand);
                if (isNaN(prev) || isNaN(current)) return;

                switch (this.operation) {
                    case '+':
                        computation = prev + current;
                        break;
                    case '-':
                        computation = prev - current;
                        break;
                    case '×':
                        computation = prev * current;
                        break;
                    case '÷':
                        if (current === 0) {
                            alert("Cannot divide by zero!");
                            return;
                        }
                        computation = prev / current;
                        break;
                    default:
                        return;
                }
                this.currentOperand = computation;
                this.operation = undefined;
                this.previousOperand = '';
                this.shouldResetScreen = true;
            }

            getDisplayNumber(number) {
                const stringNumber = number.toString();
                const integerDigits = parseFloat(stringNumber.split('.')[0]);
                const decimalDigits = stringNumber.split('.')[1];
                let integerDisplay;
                if (isNaN(integerDigits)) {
                    integerDisplay = '';
                } else {
                    integerDisplay = integerDigits.toLocaleString('en', { maximumFractionDigits: 0 });
                }
                if (decimalDigits != null) {
                    return `${integerDisplay}.${decimalDigits}`;
                } else {
                    return integerDisplay;
                }
            }

            updateDisplay() {
                this.currentOperandTextElement.innerText = 
                    this.getDisplayNumber(this.currentOperand) || '0';
                if (this.operation != null) {
                    this.previousOperandTextElement.innerText = 
                        `${this.getDisplayNumber(this.previousOperand)} ${this.operation}`;
                } else {
                    this.previousOperandTextElement.innerText = '';
                }
            }
        }

        const previousOperandTextElement = document.getElementById('previous-operand');
        const currentOperandTextElement = document.getElementById('current-operand');

        const calculator = new Calculator(previousOperandTextElement, currentOperandTextElement);

        // Update display initially and after each operation
        setInterval(() => {
            calculator.updateDisplay();
        }, 10);

        // Keyboard support
        document.addEventListener('keydown', function(event) {
            if (event.key >= '0' && event.key <= '9' || event.key === '.') {
                calculator.appendNumber(event.key);
            }
            if (event.key === '+' || event.key === '-') {
                calculator.chooseOperation(event.key);
            }
            if (event.key === '*') {
                calculator.chooseOperation('×');
            }
            if (event.key === '/') {
                event.preventDefault();
                calculator.chooseOperation('÷');
            }
            if (event.key === 'Enter' || event.key === '=') {
                calculator.compute();
            }
            if (event.key === 'Escape') {
                calculator.clear();
            }
            if (event.key === 'Backspace') {
                calculator.delete();
            }
        });