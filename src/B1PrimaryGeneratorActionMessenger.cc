//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file electromagnetic/TestEm10/src/RunMessenger.cc
/// \brief Implementation of the RunMessenger class
//
//
// $Id: RunMessenger.cc 94932 2015-12-18 09:21:29Z gcosmo $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

//#include "RunMessenger.hh"
#include "B1PrimaryGeneratorActionMessenger.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
//#include "Run.hh"
#include "B1PrimaryGeneratorAction.hh"
#include <stdlib.h>
//#include <sstream>


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

B1PrimaryGeneratorActionMessenger::B1PrimaryGeneratorActionMessenger(B1PrimaryGeneratorAction* generator)
  : G4UImessenger(),  fgenerator(generator)
//  ,fdetector(detector)
{
  //G4cout<<"hehe"<<G4endl;
  fFileNameDir = new G4UIdirectory("/B1generator");
  fFileNameDir->SetGuidance("generator config");
          
  fCmd = new G4UIcmdWithAString("/B1generator/SetPosition",this);
  fCmd->SetGuidance("set the config for different position");
  fCmd->SetParameterName("position",true);
  fCmd->SetDefaultValue ("1");
  fCmd->AvailableForStates(G4State_PreInit,G4State_Idle); 


}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

B1PrimaryGeneratorActionMessenger::~B1PrimaryGeneratorActionMessenger()
{
  delete fCmd; 
  //delete fFileNameDir;  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void B1PrimaryGeneratorActionMessenger::SetNewValue(G4UIcommand* command, G4String newValues)
{               
  if (command == fCmd) {
    fgenerator->set_position( atoi(newValues.c_str() )) ;
  } 
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

   
