/*
** EPITECH PROJECT, 2024
** B-MAT-400-BAR-4-1-206neutrinos-luca.martinet [WSL: Ubuntu]
** File description:
** neutrinos
*/

#ifndef NEUTRINOS_HPP_
    #define NEUTRINOS_HPP_

class BadArgumentError : public std::exception {
    public:
        BadArgumentError(const std::string& message) : m_message(message) {}

        virtual const char* what() const throw() {
            return m_message.c_str();
        }
    private:
        std::string m_message;
};

class Neutrinos {
    public:
        Neutrinos(double value, double arithmetic, double harmonic, double average);
        void setValue();
        void getStandardDeviation(double index);
        void getArithmeticMean(double index);
        void getRootMean(double index);
        void getHarmonicMean(double index);
        void printValue();
        double getArithmetic() const;
        double getHarmonic() const;
        double getAverage() const;
        double getRoot() const;
        double getValue() const;
    protected:
        double value;
        double arithmetic;
        double harmonic;
        double average;
        double root;
};

void loop(Neutrinos& obj);
void manHelp();
double parseInput(const std::string& input_str);

#endif /* !NEUTRINOS_HPP_ */
