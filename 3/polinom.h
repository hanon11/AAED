#ifndef _POLINOM_
#define _POLINOM_


class polinomio{
    public:
    polinomio(unsigned gradoMax);
    unsigned grado() const;
    double coeficiente(unsigned n) const;
    void coeficiente(unsigned n,double c);

    private:
    double* vector;
    unsigned grad_max;
    unsigned grad_pol;
};

#endif