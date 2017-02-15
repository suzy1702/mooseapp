#ifndef MOOSEAPPAPP_H
#define MOOSEAPPAPP_H

#include "MooseApp.h"

class MooseappApp;

template<>
InputParameters validParams<MooseappApp>();

class MooseappApp : public MooseApp
{
public:
  MooseappApp(InputParameters parameters);
  virtual ~MooseappApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MOOSEAPPAPP_H */
