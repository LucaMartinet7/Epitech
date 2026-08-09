/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD07am-luca.martinet
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
    #define WARPSYSTEM_HPP_

namespace WarpSystem
{
    class QuantumReactor
    {
    public:
        QuantumReactor();
        bool isStable();
        void setStability(bool stability);
    private:
        bool _stability;
    };

    class Core
    {
    public:
        Core(QuantumReactor *coreReactor);
        WarpSystem::QuantumReactor *checkReactor();
    private:
        WarpSystem::QuantumReactor *_coreReactor;
    };
}

#endif /* !WARPSYSTEM_HPP_ */
