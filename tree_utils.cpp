//
// Created by Luis Pelegrina Gutiérrez on 8/5/24.
//
#include "Includes.h"

double POT;
double spill;

string* file_name =  nullptr;

//Event variables                                                                                                                                                           
unsigned int event_ID;
int num_gen_evts;

//MCTruth variables
//Consult https://internal.dunescience.org/doxygen/classsimb_1_1MCNeutrino.html#a8e213917487f1f5cd52ca5280d33a777 for information on the numbers meaning
int nu_PDG;
double nu_E0;
double nu_weight; 
unsigned int nu_interaction_mode;
unsigned int nu_interaction_type;
int nu_CC_NC;
int nu_target;
int nu_HitNuc;
int nu_HitQuark;
double nu_W;
double nu_X;
double nu_Y;
double 	nu_QSqr;

int gen_index;

//MCTruth Particles variables
std::vector<int>* gen_part_trackID = new std::vector<int>;
std::vector<int>* gen_part_statusCode= new std::vector<int>;
std::vector<int>* gen_part_mother = new std::vector<int>;
std::vector<int>* gen_part_PDGcode = new std::vector<int>;
std::vector<double>* gen_part_mass = new std::vector<double>;
std::vector<double>* gen_part_E0 = new std::vector<double>;
std::vector<double>* gen_part_start_pos_X = new std::vector<double>;
std::vector<double>* gen_part_start_pos_Y = new std::vector<double>;
std::vector<double>* gen_part_start_pos_Z = new std::vector<double>;
std::vector<double>* gen_part_P0_Y = new std::vector<double>;
std::vector<double>* gen_part_P0_Z = new std::vector<double>;
std::vector<double>* gen_part_P0_X = new std::vector<double>;

//Geant4 Particles variables
std::vector<int>* g4_part_trackID = new std::vector<int>;
std::vector<int>* g4_part_mother = new std::vector<int>;
std::vector<int>* g4_part_PDGcode = new std::vector<int>;
std::vector<double>* g4_part_mass = new std::vector<double>;
std::vector<double>* g4_part_E0 = new std::vector<double>;
std::vector<double>* g4_part_Ef = new std::vector<double>;
    
std::vector<double>* g4_part_start_pos_X = new std::vector<double>;
std::vector<double>* g4_part_start_pos_Y = new std::vector<double>;
std::vector<double>* g4_part_start_pos_Z = new std::vector<double>;
std::vector<double>* g4_part_end_pos_X = new std::vector<double>;
std::vector<double>* g4_part_end_pos_Y = new std::vector<double>;
std::vector<double>* g4_part_end_pos_Z = new std::vector<double>;

std::vector<double>* g4_part_P0_X = new std::vector<double>;
std::vector<double>* g4_part_P0_Y = new std::vector<double>;
std::vector<double>* g4_part_P0_Z = new std::vector<double>;
std::vector<double>* g4_part_Pf_X = new std::vector<double>;
std::vector<double>* g4_part_Pf_Y = new std::vector<double>;
std::vector<double>* g4_part_Pf_Z = new std::vector<double>;
  
std::vector<std::string>* g4_part_process = new std::vector<string>;
std::vector<std::string>* g4_part_end_process = new std::vector<string>;

void set_branch(TTree* tree) {

  tree->SetBranchAddress("file_name", &file_name);
  tree->SetBranchAddress("event_ID", &event_ID);
  tree->SetBranchAddress("gen_index", &gen_index);

  tree->SetBranchAddress("nu_PDG", &nu_PDG);
  tree->SetBranchAddress("nu_E0", &nu_E0);
  tree->SetBranchAddress("nu_weight", &nu_weight); 
  tree->SetBranchAddress("nu_interaction_mode", &nu_interaction_mode);
  tree->SetBranchAddress("nu_interaction_type", &nu_interaction_type);
  tree->SetBranchAddress("nu_CC_NC", &nu_CC_NC);
  tree->SetBranchAddress("nu_target", &nu_target);
  tree->SetBranchAddress("nu_HitNuc", &nu_HitNuc);
  tree->SetBranchAddress("nu_HitQuark", &nu_HitQuark);
  tree->SetBranchAddress("nu_W", &nu_W);
  tree->SetBranchAddress("nu_X", &nu_X);
  tree->SetBranchAddress("nu_Y", &nu_Y);
  tree->SetBranchAddress("nu_QSqr", &nu_QSqr);  
  tree->SetBranchAddress("gen_index", &gen_index);

  //MCTruth Particles variables
  tree->SetBranchAddress("gen_part_trackID", &gen_part_trackID);
  tree->SetBranchAddress("gen_part_statusCode", &gen_part_statusCode);
  tree->SetBranchAddress("gen_part_mother", &gen_part_mother);
  tree->SetBranchAddress("gen_part_PDGcode", &gen_part_PDGcode);
  tree->SetBranchAddress("gen_part_mass", &gen_part_mass);
  tree->SetBranchAddress("gen_part_E0", &gen_part_E0);
  tree->SetBranchAddress("gen_part_start_pos_X", &gen_part_start_pos_X);
  tree->SetBranchAddress("gen_part_start_pos_Y", &gen_part_start_pos_Y);
  tree->SetBranchAddress("gen_part_start_pos_Z", &gen_part_start_pos_Z);
  tree->SetBranchAddress("gen_part_P0_X", &gen_part_P0_X);
  tree->SetBranchAddress("gen_part_P0_Y", &gen_part_P0_Y);
  tree->SetBranchAddress("gen_part_P0_Z", &gen_part_P0_Z);

  //Geant4 Particles variables
  tree->SetBranchAddress("g4_part_trackID", &g4_part_trackID);
  tree->SetBranchAddress("g4_part_mother", &g4_part_mother);
  tree->SetBranchAddress("g4_part_PDGcode", &g4_part_PDGcode);
  tree->SetBranchAddress("g4_part_mass", &g4_part_mass);
  tree->SetBranchAddress("g4_part_E0", &g4_part_E0);
  tree->SetBranchAddress("g4_part_Ef", &g4_part_Ef);
    
  tree->SetBranchAddress("g4_part_start_pos_X", &g4_part_start_pos_X);
  tree->SetBranchAddress("g4_part_start_pos_Y", &g4_part_start_pos_Y);
  tree->SetBranchAddress("g4_part_start_pos_Z", &g4_part_start_pos_Z);
  tree->SetBranchAddress("g4_part_end_pos_X", &g4_part_end_pos_X);
  tree->SetBranchAddress("g4_part_end_pos_Y", &g4_part_end_pos_Y);
  tree->SetBranchAddress("g4_part_end_pos_Z", &g4_part_end_pos_Z);

  tree->SetBranchAddress("g4_part_P0_X", &g4_part_P0_X);
  tree->SetBranchAddress("g4_part_P0_Y", &g4_part_P0_Y);
  tree->SetBranchAddress("g4_part_P0_Z", &g4_part_P0_Z);
  tree->SetBranchAddress("g4_part_Pf_X", &g4_part_Pf_X);
  tree->SetBranchAddress("g4_part_Pf_Y", &g4_part_Pf_Y);
  tree->SetBranchAddress("g4_part_Pf_Z", &g4_part_Pf_Z);
  
  tree->SetBranchAddress("g4_part_process", &g4_part_process);
  tree->SetBranchAddress("g4_part_end_process", &g4_part_end_process);
}




void set_branch_subtree(TTree* tree) {
  tree->SetBranchAddress("POT", &POT);
  tree->SetBranchAddress("spill", &spill);
  tree->SetBranchAddress("num_gen_evts", &num_gen_evts);

}