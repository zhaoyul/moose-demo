//* This file is part of the MOOSE framework
//* https://mooseframework.inl.gov
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "MyFirstAppTestApp.h"
#include "MyFirstAppApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
MyFirstAppTestApp::validParams()
{
  InputParameters params = MyFirstAppApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

MyFirstAppTestApp::MyFirstAppTestApp(InputParameters parameters) : MooseApp(parameters)
{
  MyFirstAppTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

MyFirstAppTestApp::~MyFirstAppTestApp() {}

void
MyFirstAppTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  MyFirstAppApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"MyFirstAppTestApp"});
    Registry::registerActionsTo(af, {"MyFirstAppTestApp"});
  }
}

void
MyFirstAppTestApp::registerApps()
{
  registerApp(MyFirstAppApp);
  registerApp(MyFirstAppTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
MyFirstAppTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MyFirstAppTestApp::registerAll(f, af, s);
}
extern "C" void
MyFirstAppTestApp__registerApps()
{
  MyFirstAppTestApp::registerApps();
}
