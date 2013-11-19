/* 
	 * Fast matrix method. Easy to describe, but has a constant factor slowdown compared to doubling method.
	 * [1 1]^n   [F(n+1) F(n)  ]
	 * [1 0]   = [F(n)   F(n-1)]
	 */
	private static BigInteger fastFibonacciMatrix(int n) {
		BigInteger[] matrix = {BigInteger.ONE, BigInteger.ONE, BigInteger.ONE, BigInteger.ZERO};
		return pow(matrix, n)[1];
	}
	
	// Computes the power of a matrix
	private static BigInteger[] pow(BigInteger[] matrix, int n) {
		if (n < 0)
			throw new IllegalArgumentException();
		BigInteger[] result = {BigInteger.ONE, BigInteger.ZERO, BigInteger.ZERO, BigInteger.ONE};
		while (n != 0) {  // Exponentiation by squaring
			if (n % 2 != 0)
				result = multiply(result, matrix);
			n /= 2;
			matrix = multiply(matrix, matrix);
		}
		return result;
	}
	
	// Multiplies two matrices
	private static BigInteger[] multiply(BigInteger[] x, BigInteger[] y) {
		return new BigInteger[] {
			multiply(x[0], y[0]).add(multiply(x[1], y[2])),
			multiply(x[0], y[1]).add(multiply(x[1], y[3])),
			multiply(x[2], y[0]).add(multiply(x[3], y[2])),
			multiply(x[2], y[1]).add(multiply(x[3], y[3]))
		};
	}
	
