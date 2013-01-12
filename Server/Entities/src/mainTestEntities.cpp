#include "Scenario.h"
#include "TestMob.h"

#include <iostream> // remove

int		main()
{
  std::cout << "\n---- BEGIN ----\n" << std::endl;

  std::cout << "Création d'un scenario d'une durée de 5 unitées de temps." << std::endl;
  Scenario * scenar = new Scenario(5.f);
  std::cout << "Création d'un Timepoint (spawn de monstre a un point donné)" << std::endl;
  Timepoint tp1;
  HitBox hb; hb.xmin_ = 1; hb.xmax_ = 4; hb.ymin_ = 1; hb.ymax_ = 4;
  Point dep; dep.x_ = 32; dep.y_ = 27;
  tp1.spawn_ = new TestMob(3,1,101,hb,dep);
  tp1.time_ = 3.f;
  std::cout << "Ajout du timepoint dans le scenario" << std::endl;
  scenar->addNewEvent(tp1);

  std::cout << "\n===== TEST TIME =====\n" << std::endl;

  std::cout << "\n===== END OF TEST TIME =====\n" << std::endl;

  std::cout << "\n---- END ----\n" << std::endl;

  return 0;
}
