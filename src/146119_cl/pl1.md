# Propositional Logic 1

## Intuitive interpretation

### Meaning

- $\lnot x$ - negation
- $(x \land y)$ - conjunction (and)
- $(x \lor y)$ -disjunction (or)
- $(x \to y)$ - conditional/implication (if…then)
- $(x \leftrightarrow y)$ - biconditional (if and only if)

## Truth-functional semantics for complex formulas

- $v(\lnot x)=1 \iff v(x)=0$
- $v(x \land y)=1 \iff v(x)=1 \land v(y)=1$
- $v(x \lor y)=1 \iff v(x)=1 \lor v(y)=1$
- $v(x \to y)=1 \iff v(x)=0 \lor v(y)=1$
- $v(x \leftrightarrow y)=1 \iff v(x)=v(y)$

## Truth-tables

//Todo