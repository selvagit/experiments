import React, { useState, useEffect } from 'react';

const Display = ({ expression, result }) => {
    const [displayValue, setDisplayValue] = useState('');

    useEffect(() => {
        setDisplayValue(`${expression} = ${result}`);
    }, [expression, result]);

    return (
        <div className="calculator-display">
            <div className="display-value">{displayValue}</div>
        </div>
    );
};

export default Display;