#pragma once

template <class A, class B>
class Pair {
public:
	Pair(A, B);
	Pair(const Pair &);
	~Pair();

	A getA() const;
	B getB() const;
	void setA(A);
	void setB(B);
	Pair<A, B> operator =(const Pair &);

private:
	A *a;
	B b;
};