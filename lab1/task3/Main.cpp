#include "Duck/MallardDuck.h"
#include "Duck/RedHeadDuck.h"
#include "Duck/ArtificialDuck.h"
#include "Duck/DecoyDuck.h"
#include "DuckFunctions.h"

int main()
{
  std::vector<std::unique_ptr<Duck>> ducks;
  ducks.reserve(4);
  ducks.push_back(std::make_unique<MallardDuck>());
  ducks.push_back(std::make_unique<RedheadDuck>());
  ducks.push_back(std::make_unique<ArtificialDuck>());
  ducks.push_back(std::make_unique<DecoyDuck>());

  for (const auto& duck : ducks)
  {
    PlayWithDuck(*duck);
  }
}