/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD07am-luca.martinet
** File description:
** WarpSystem
*/

#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor()
{
  this->_stability  = true;
}

bool WarpSystem::QuantumReactor::isStable()
{
  return this->_stability;
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
  this->_stability = stability;
}

WarpSystem::Core::Core(QuantumReactor *coreReactor)
{
  this->_coreReactor = coreReactor;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
  return this->_coreReactor;
}
