/*
** EPITECH PROJECT, 2024
** B-PDG-300-BAR-3-1-PDGD08-luca.martinet
** File description:
** Droid
*/

#include <iostream>
#include "Droid.hpp"

Droid::Droid(std::string serial) : Id(serial)
{
    std::cout << "Droid '" << Id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &droid) : Id(droid.Id), Energy(droid.Energy), Status(new std::string(*droid.Status))
{
    std::cout << "Droid '" << droid.Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    delete Status;
    std::cout << "Droid '" << Id << "' Destroyed" << std::endl;
}

std::string Droid::getId() const
{
    return Id;
}

void Droid::setId(std::string id)
{
    Id = id;
}

std::size_t Droid::getEnergy() const
{
    return Energy;
}

void Droid::setEnergy(std::size_t energy)
{
    Energy = std::min((std::size_t)100, std::max(energy, (std::size_t)0));
}

std::size_t Droid::getAttack() const
{
    return Attack;
}

std::size_t Droid::getToughness() const
{
    return Toughness;
}

std::string *Droid::getStatus() const
{
    return Status;
}

void Droid::setStatus(std::string *status)
{
    Status = status;
}

Droid &Droid::operator=(const Droid &source)
{
    if (this == &source)
        return *this;

    delete Status;
    Id = source.Id;
    Energy = source.Energy;
    Status = new std::string(*source.Status);
    return *this;
}

bool Droid::operator==(const Droid &other) const
{
    return Attack == other.Attack &&
           Energy == other.Energy &&
           Toughness == other.Toughness &&
           *Status == *(other.Status) &&
           Id == other.Id;
}

bool Droid::operator!=(const Droid &other) const
{
    return !(Attack == other.Attack &&
             Energy == other.Energy &&
             Toughness == other.Toughness &&
             *Status == *(other.Status) &&
             Id == other.Id);
}

void Droid::operator<<(std::size_t &amount)
{
    std::size_t required = std::min<std::size_t>(100 - Energy, amount);

    Energy += required;
    amount -= required;
}

std::ostream &operator<<(std::ostream& stream, const Droid &droid)
{
    return stream << "Droid '" << droid.getId() << "', " << *droid.getStatus() << ", " << droid.getEnergy();
}

int main ()
{
    Droid d ;
    Droid d1 ( "Avenger" ) ;
    size_t Durasel = 200;
    std :: cout << d << std :: endl ;
    std :: cout << d1 << std :: endl ;
    d = d1 ;
    d . setStatus ( new std :: string ( "Kill Kill Kill!" ) ) ;
    d << Durasel ;
    std :: cout << d << "--" << Durasel << std :: endl ;
    Droid d2 = d ;
    d . setId ( "Rex" ) ;
    std :: cout << ( d2 != d ) << std :: endl ;
    return 0;
}