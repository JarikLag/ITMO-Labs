package expression;

public strictfp class Subtract extends AbstractBinaryOperator {
    public Subtract(AnyExpression first, AnyExpression second) {
        super(first, second);
    }

    protected int calculate(int first, int second) {
        return first - second;
    }

    protected double calculate(double first, double second) {
        return first - second;
    }
}
