/*
Write these enums to represent a mathematical expression:
  - One enum is called `Operation` and can be: `Add`, `Sub`, `Mul`, `Div`.
  - One enum is called `Expression` an can be:
      - `Number` (contain inside an i32)
      - `Operation` (contain inside a let Expression, a right Expression and an Operation)

Note: the let and right expression must be wrapped around a Box

    `Box<Expression>`.

You will see Boxes further into the course,
from now you just need to know that you can build a box using

    `let my_box = Box::new(my_expression)`

and you can get the value inside the box by dereferencing it

    `let value_inside = *my_box`

Write a function `evaluate_expression` that take as input an Expression,
and return a Result with a i32 if the result is evaluated correctly,
or a string if an error occurs.
*/

use std::fmt::Display;

enum Operation {
    Add,
    Sub,
    Mul,
    Div,
}

enum Expression {
    Operation {
        left: Box<Expression>,
        op: Operation,
        right: Box<Expression>,
    },
    Number(i32),
}

impl Display for Operation {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Operation::Add => write!(f, "+"),
            Operation::Sub => write!(f, "-"),
            Operation::Mul => write!(f, "*"),
            Operation::Div => write!(f, "/"),
        }
    }
}

// just to have a nice output, not required for the exercise
impl Display for Expression {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Expression::Operation { left, op, right } => {
                write!(f, "({} {} {})", left, op, right)
            }
            Expression::Number(n) => write!(f, "{}", n),
        }
    }
}

fn evaluate_expression(expression: &Expression) -> Result<i32, &str> {
    match expression {
        Expression::Operation { left, op, right } => {
            let val_left = evaluate_expression(left)?;
            let val_right = evaluate_expression(right)?;

            match op {
                Operation::Add => {
                    let r = val_left.checked_add(val_right);
                    match r {
                        Option::None => Result::Err("overflow"),
                        Option::Some(v) => Result::Ok(v),
                    }
                }
                Operation::Sub => {
                    let r = val_left.checked_sub(val_right);
                    match r {
                        Option::None => Result::Err("overflow"),
                        Option::Some(v) => Result::Ok(v),
                    }
                }
                Operation::Mul => {
                    let r = val_left.checked_mul(val_right);
                    match r {
                        Option::None => Result::Err("overflow"),
                        Option::Some(v) => Result::Ok(v),
                    }
                }
                Operation::Div => {
                    let r = val_left.checked_div(val_right);
                    match r {
                        Option::None => Result::Err("division by zero"),
                        Option::Some(v) => Result::Ok(v),
                    }
                }
            }
        }
        Expression::Number(n) => Result::Ok(*n),
    }
}
