#include "Pair.h"

template <class A, class B> 
Pair<A, B>::Pair(A a, B b) : a(new A(a)), b(b) {
}

template <class A, class B>
Pair<A, B>::Pair(const Pair &pair) : a(new A(pair.getA())), b(pair.getB()) {
}

template <class A, class B>
Pair<A, B>::~Pair() {
	delete a;
}

template <class A, class B>
A Pair<A, B>::getA() const {
	return *a;
}

template <class A, class B>
B Pair<A, B>::getB() const {
	return b;
}

template <class A, class B>
void Pair<A, B>::setA(A newA) {
	*a = newA;
}

template <class A, class B>
void Pair<A, B>::setB(B newB) {
	b = newB;
}

template <class A, class B>
Pair<A, B> Pair<A, B>::operator=(const Pair &pair) {
	*a = pair.getA();
	b = pair.getB();
	return *this;
}

template class Pair<float, int>;
template class Pair<Pair<float, int>, Pair<float, int>>;

