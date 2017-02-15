#include "MooseappApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<MooseappApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

MooseappApp::MooseappApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  MooseappApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  MooseappApp::associateSyntax(_syntax, _action_factory);
}

MooseappApp::~MooseappApp()
{
}

// External entry point for dynamic application loading
extern "C" void MooseappApp__registerApps() { MooseappApp::registerApps(); }
void
MooseappApp::registerApps()
{
  registerApp(MooseappApp);
}

// External entry point for dynamic object registration
extern "C" void MooseappApp__registerObjects(Factory & factory) { MooseappApp::registerObjects(factory); }
void
MooseappApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void MooseappApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { MooseappApp::associateSyntax(syntax, action_factory); }
void
MooseappApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
