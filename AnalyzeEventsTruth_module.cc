////////////////////////////////////////////////////////////////////////
// Class:       AnalyzeEventsTruth
// Plugin Type: analyzer (Unknown Unknown)
// File:        AnalyzeEventsTruth_module.cc
//
// Generated at Thu Jan 26 04:44:06 2023 by Luis Pelegrina gutierrez using cetskelgen
// from  version .
////////////////////////////////////////////////////////////////////////

// Additional Framework includes                                                                                                                                                        
#include "art_root_io/TFileService.h"

// Additional LArSoft includes                                                                                                                                                          
#include "art/Framework/Core/FileBlock.h"
#include "art/Framework/Core/EDAnalyzer.h"
#include "art/Framework/Core/ModuleMacros.h"
#include "art/Framework/Principal/Event.h"
#include "art/Framework/Principal/Handle.h"
#include "art/Framework/Principal/Run.h"
#include "art/Framework/Principal/SubRun.h"

#include "nusimdata/SimulationBase/MCParticle.h"
#include "nusimdata/SimulationBase/MCTruth.h"

#include "larcoreobj/SimpleTypesAndConstants/RawTypes.h"
#include "larcoreobj/SummaryData/POTSummary.h"

#include "larcore/Geometry/Geometry.h"
#include "larcorealg/Geometry/GeometryCore.h"

#include "lardataobj/MCBase/MCTrack.h"

#include "lardataalg/DetectorInfo/DetectorPropertiesData.h"
#include "lardataalg/DetectorInfo/DetectorPropertiesStandard.h"
#include "lardata/DetectorInfoServices/DetectorClocksService.h"
#include "lardata/DetectorInfoServices/DetectorPropertiesService.h"

#include "canvas/Utilities/InputTag.h"
#include "fhiclcpp/ParameterSet.h"
#include "messagefacility/MessageLogger/MessageLogger.h"

#include "canvas/Utilities/InputTag.h"
#include "canvas/Persistency/Common/Ptr.h"
#include "canvas/Persistency/Common/PtrVector.h"
#include "canvas/Persistency/Common/FindMany.h"
#include "canvas/Persistency/Common/FindManyP.h"
#include "canvas/Persistency/Common/FindOneP.h"


// ROOT includes                                                                                                                                                                        
#include "TLorentzVector.h"
#include "TTree.h"
#include "TFile.h"
#include "TH1F.h"
#include "TGraph.h"
#include "TInterpreter.h"
#include "TTimeStamp.h"
#include <larcorealg/Geometry/Exceptions.h>

#include <vector>
#include <limits>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdio.h>                                                                                                                                                                       
#include <string>


namespace test {
  class AnalyzeEventsTruth;
}


class test::AnalyzeEventsTruth : public art::EDAnalyzer {
public:
  explicit AnalyzeEventsTruth(fhicl::ParameterSet const& p);
  // The compiler-generated destructor is fine for non-base
  // classes without bare pointers or other resource use.

  // Plugins should not be copied or assigned.
  AnalyzeEventsTruth(AnalyzeEventsTruth const&) = delete;
  AnalyzeEventsTruth(AnalyzeEventsTruth&&) = delete;
  AnalyzeEventsTruth& operator=(AnalyzeEventsTruth const&) = delete;
  AnalyzeEventsTruth& operator=(AnalyzeEventsTruth&&) = delete;
  
  // Required functions.
  void analyze(art::Event const& e) override;

  // Selected optional functions.
  void beginJob() override;
  void endJob() override;

  void respondToOpenInputFile(art::FileBlock const&); 

  int GetTotalGenEvents(const art::Event &e);

  void beginSubRun(const art::SubRun &sr);
  void endSubRun(const art::SubRun &sr);

private:


  TTree *fSubRunTree;
  double POT;
  double spill;

  // Create out output tree.                                                                                                                                                          
  TTree *fTree;
  std::string file_name;

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
  double nu_QSqr;

  int gen_index;

  //MCTruth Particles variables
  std::vector<int> gen_part_trackID;
  std::vector<int> gen_part_statusCode;
  std::vector<int> gen_part_mother;
  std::vector<int> gen_part_PDGcode;
  std::vector<double> gen_part_mass;
  std::vector<double> gen_part_E0;
  std::vector<double> gen_part_start_pos_X;
  std::vector<double> gen_part_start_pos_Y;
  std::vector<double> gen_part_start_pos_Z;
  std::vector<double> gen_part_P0_Y;
  std::vector<double> gen_part_P0_Z;
  std::vector<double> gen_part_P0_X;

  //Geant4 Particles variables
  std::vector<int> g4_part_trackID;
  std::vector<int> g4_part_mother;
  std::vector<int> g4_part_PDGcode;
  std::vector<double> g4_part_mass;
  std::vector<double> g4_part_E0;
  std::vector<double> g4_part_Ef;
    
  std::vector<double> g4_part_start_pos_X;
  std::vector<double> g4_part_start_pos_Y;
  std::vector<double> g4_part_start_pos_Z;
  std::vector<double> g4_part_end_pos_X;
  std::vector<double> g4_part_end_pos_Y;
  std::vector<double> g4_part_end_pos_Z;

  std::vector<double> g4_part_P0_X;
  std::vector<double> g4_part_P0_Y;
  std::vector<double> g4_part_P0_Z;
  std::vector<double> g4_part_Pf_X;
  std::vector<double> g4_part_Pf_Y;
  std::vector<double> g4_part_Pf_Z;
  
  std::vector<std::string> g4_part_process;
  std::vector<std::string> g4_part_end_process;

  const std::string MCTruth_label;
  const std::string MCParticle_label;
  const std::string POTModule_label;
  bool verbose = false;

};


test::AnalyzeEventsTruth::AnalyzeEventsTruth(fhicl::ParameterSet const& p)
  : EDAnalyzer{p} ,
  // More initializers here.
    MCTruth_label(p.get<std::string>("MCTruthLabel")) ,
    MCParticle_label(p.get<std::string>("MCParticleLabel")),
    POTModule_label(p.get<std::string>("POTLabel")),
    verbose(p.get<bool>("Verbose"))
    
    
{
  // Call appropriate consumes<>() for any products to be retrieved by this module.
}

int test::AnalyzeEventsTruth::GetTotalGenEvents(const art::Event &e)
{
  int nGenEvt = 0;
  for (const art::ProcessConfiguration &process: e.processHistory()) {
    std::optional<fhicl::ParameterSet> genConfig = e.getProcessParameterSet(process.processName());
    if (genConfig && genConfig->has_key("source") && genConfig->has_key("source.maxEvents") && genConfig->has_key("source.module_type") ) {
      int maxEvents = genConfig->get<int>("source.maxEvents");
      std::string moduleType = genConfig->get<std::string>("source.module_type");
      if (moduleType == "EmptyEvent") {
        nGenEvt += maxEvents;
      }
    }
  }

  return nGenEvt;
}

void test::AnalyzeEventsTruth::beginSubRun(const art::SubRun &sr)
{
  //Load the POT and cout it
  art::Handle<sumdata::POTSummary> POT_handle;
  sr.getByLabel(POTModule_label, POT_handle);
  if(!POT_handle.isValid()){
    std::cout << "POT product " << POTModule_label << " not found..." << std::endl;
    //throw std::exception();
  }

  POT = 0;
  spill = 0;
  if(!POT_handle.isValid()){
    POT = 0;
    spill = 1;
  }else {
    POT = POT_handle->totpot;
    spill = POT_handle->totspills;
 } 

}

void test::AnalyzeEventsTruth::endSubRun(const art::SubRun &sr)
{
  fSubRunTree->Fill();
}


void test::AnalyzeEventsTruth::analyze(art::Event const& e) {
    //Reset all variables at the start of the analysis of an event
    nu_PDG = 0;
    nu_E0 = 0;
    nu_weight = 0;
    nu_interaction_mode = 0;
    nu_interaction_type = 0;
    nu_CC_NC = 0;
    nu_target = 0;
    nu_HitNuc = 0;
    nu_HitQuark = 0;
    nu_W = 0;
    nu_X = 0;
    nu_Y = 0;
    nu_QSqr = 0;
    gen_index = 0;

    //Reset the vectors with MCTruth particles information
    gen_part_trackID.clear();
    gen_part_statusCode.clear();
    gen_part_mother.clear();
    gen_part_PDGcode.clear();
    gen_part_mass.clear();
    gen_part_E0.clear();
    gen_part_start_pos_X.clear();
    gen_part_start_pos_Y.clear();
    gen_part_start_pos_Z.clear();
    gen_part_P0_X.clear();
    gen_part_P0_Y.clear();
    gen_part_P0_Z.clear();


    //Reset the vectors with geant4 particles information
    g4_part_trackID.clear();
    g4_part_mother.clear();
    g4_part_PDGcode.clear();
    g4_part_mass.clear();
    g4_part_E0.clear();
    g4_part_Ef.clear();

    g4_part_start_pos_X.clear();
    g4_part_start_pos_Y.clear();
    g4_part_start_pos_Z.clear();
    g4_part_end_pos_X.clear();
    g4_part_end_pos_Y.clear();
    g4_part_end_pos_Z.clear();

    g4_part_P0_X.clear();
    g4_part_P0_Y.clear();
    g4_part_P0_Z.clear();
    g4_part_Pf_X.clear();
    g4_part_Pf_Y.clear();
    g4_part_Pf_Z.clear();

    g4_part_process.clear();
    g4_part_end_process.clear();

    //Fill the event ID information and the total number of generated events
    event_ID = e.id().event();
    num_gen_evts = GetTotalGenEvents(e);

    //Acceso a MCTruth
    art::Handle <std::vector<simb::MCTruth>> MCT_handle;
    std::vector<art::Ptr < simb::MCTruth>>
    MCT_vec;
    if (e.getByLabel(MCTruth_label, MCT_handle))
        art::fill_ptr_vector(MCT_vec, MCT_handle);

    //Truth Information
    for (const art::Ptr <simb::MCTruth> &MCT: MCT_vec) {
        nu_PDG = MCT->GetNeutrino().Nu().PdgCode();
        nu_E0 = MCT->GetNeutrino().Nu().E(0);
        nu_weight = MCT->GetNeutrino().Nu().Weight();

        nu_interaction_mode = MCT->GetNeutrino().Mode();
        nu_interaction_type = MCT->GetNeutrino().InteractionType();
        nu_CC_NC = MCT->GetNeutrino().CCNC();

        nu_HitNuc = MCT->GetNeutrino().HitNuc();
        nu_target = MCT->GetNeutrino().Target();
        nu_HitQuark = MCT->GetNeutrino().HitQuark();
        nu_W = MCT->GetNeutrino().W();
        nu_X = MCT->GetNeutrino().X();
        nu_Y = MCT->GetNeutrino().Y();
        nu_QSqr = MCT->GetNeutrino().QSqr();

        if (MCT->Origin() == 0) {
            gen_index = 0;
        } else if (MCT->Origin() == 1) {
            gen_index = 1;
        } else if (MCT->Origin() == 2) {
            gen_index = 2;
        }

        if (verbose) {
            std::cout << "---- event " << event_ID << " ----" << std::endl;
            std::cout << "Neutrino Information: " << std::endl;
            std::cout << "Neutrino properties: " << std::endl;
            std::cout << "PDG: " << nu_PDG << " Energy: " << nu_E0 << " weight: " << nu_weight << std::endl;
            std::cout << "Interaction mode: " << nu_interaction_mode << " Interaction type: " << nu_interaction_type
                      << " CCorNC: " << nu_CC_NC << std::endl;
            std::cout << "Target: " << nu_target << " HitNuc: " << nu_HitNuc << " HitQuark: " << nu_HitQuark
                      << std::endl;
            std::cout << " W: " << nu_W << " X: " << nu_X << " Y: " << nu_Y << " Qsqr: " << nu_QSqr << std::endl;
            std::cout << std::endl;
        }


        for (int i = 0; i < MCT->NParticles(); i++) {
            simb::MCParticle MCP = MCT->GetParticle(i);

            gen_part_trackID.push_back(MCP.TrackId());
            gen_part_statusCode.push_back(MCP.StatusCode());
            gen_part_mother.push_back(MCP.Mother());
            gen_part_PDGcode.push_back(MCP.PdgCode());
            gen_part_mass.push_back(MCP.Mass());
            gen_part_E0.push_back(MCP.E(0));
            gen_part_start_pos_X.push_back(MCP.Vx(0));
            gen_part_start_pos_Y.push_back(MCP.Vy(0));
            gen_part_start_pos_Z.push_back(MCP.Vz(0));
            gen_part_P0_X.push_back(MCP.Px(0));
            gen_part_P0_Y.push_back(MCP.Py(0));
            gen_part_P0_Z.push_back(MCP.Pz(0));

            if (verbose) {
                std::cout << "ID: " << MCP.TrackId() << " Status code: "<< MCP.StatusCode() <<  " Mother: " << MCP.Mother() << std::endl;
                std::cout << "   PDGCode: " << MCP.PdgCode() << " Mass: " << MCP.Mass() << " Energy: " << MCP.E(0) << std::endl;
                std::cout << "   Start Pos (x,y,z) : (" << MCP.Vx(0) << ", " << MCP.Vy(0) << ", " << MCP.Vz(0)  << ")" << std::endl;
                std::cout << "   Start Momentum (x,y,z) : (" << MCP.Px(0) << ", " << MCP.Py(0) << ", " << MCP.Pz(0)  << ")" << std::endl;

            }
        }

        if (verbose) std::cout << std::endl;
    }


    art::Handle<std::vector<simb::MCParticle>> MCP_handle;
    std::vector<art::Ptr<simb::MCParticle>> MCP_vec;
    if (e.getByLabel(MCParticle_label, MCP_handle))
        art::fill_ptr_vector(MCP_vec, MCP_handle);

    for (const art::Ptr<simb::MCParticle>& MCP : MCP_vec) {
        const size_t numberTrajectoryPoints = MCP->NumberTrajectoryPoints();
        const int last = numberTrajectoryPoints - 1;

        g4_part_trackID.push_back(MCP->TrackId());
        g4_part_mother.push_back(MCP->Mother());
        g4_part_PDGcode.push_back(MCP->PdgCode());
        g4_part_mass.push_back(MCP->Mass());
        g4_part_E0.push_back(MCP->E(0));
        g4_part_Ef.push_back(MCP->E(last));
    
        g4_part_start_pos_X.push_back(MCP->Vx(0));
        g4_part_start_pos_Y.push_back(MCP->Vy(0));
        g4_part_start_pos_Z.push_back(MCP->Vz(0));
        g4_part_end_pos_X.push_back(MCP->Vx(last));
        g4_part_end_pos_Y.push_back(MCP->Vy(last));
        g4_part_end_pos_Z.push_back(MCP->Vz(last));

        g4_part_P0_X.push_back(MCP->Px(0));
        g4_part_P0_Y.push_back(MCP->Py(0));
        g4_part_P0_Z.push_back(MCP->Pz(0));
        g4_part_Pf_X.push_back(MCP->Px(last));
        g4_part_Pf_Y.push_back(MCP->Py(last));
        g4_part_Pf_Z.push_back(MCP->Pz(last));

        g4_part_process.push_back(MCP->Process());
        g4_part_end_process.push_back(MCP->EndProcess());

        if (verbose) {
            std::cout << "ID: " << MCP->TrackId() << " Mother: " << MCP->Mother() << std::endl;
            std::cout << "   PDGCode: " << MCP->PdgCode() << " Mass: " << MCP->Mass()
            << " Initial Energy: " << MCP->E(0) << " Final Energy: " << MCP->E(last) << std::endl;
            std::cout << "   Start Pos (x,y,z) : (" <<  MCP->Vx(0) << ", " << MCP->Vy(0)
            << ", " << MCP->Vz(0) << ")" << std::endl;
            std::cout << "   End Pos (x,y,z) : (" << MCP->Vx(last) << ", " << MCP->Vy(last) << ", "
            << MCP->Vz(last) << ")" << std::endl;

            std::cout << "   Start Momentum (x,y,z) : (" << MCP->Px(0) << ", " << MCP->Py(0) << ", "
            << MCP->Pz(0) << ")" << std::endl;
            std::cout << "   End Momentum (x,y,z) : (" << MCP->Px(last) << ", " << MCP->Py(last) << ", "
            << MCP->Pz(last) << ")" << std::endl;
            std::cout << "   Process: " << MCP->Process() << std::endl;
            std::cout << "   End_process: " << MCP->EndProcess() << std::endl;

        }
    }
    if (verbose) std::cout << std::endl;

  
  fTree->Fill();

}

  //std::cout << std::endl;


void test::AnalyzeEventsTruth::respondToOpenInputFile(art::FileBlock const& fb) { 
  file_name = fb.fileName();
}

void test::AnalyzeEventsTruth::beginJob()
{
  // Implementation of optional member function here.                                                                                                                                   
  art::ServiceHandle<art::TFileService> tfs;

                                                                                                                             
  fSubRunTree = tfs->make<TTree>("subrun_tree", "SubRun Tree");
  fSubRunTree->Branch("POT", &POT);
  fSubRunTree->Branch("spill", &spill);
  fSubRunTree->Branch("num_gen_evts", &num_gen_evts);


  // Get the TFileService to create out output tree for us                                                                                                                              
  fTree = tfs->make<TTree>("tree", "Output Tree");

  // Add branches to the TTree   

  fTree->Branch("file_name", &file_name);
  fTree->Branch("event_ID", &event_ID);
  fTree->Branch("gen_index", &gen_index);

  fTree->Branch("nu_PDG", &nu_PDG);
  fTree->Branch("nu_E0", &nu_E0);
  fTree->Branch("nu_weight", &nu_weight); 
  fTree->Branch("nu_interaction_mode", &nu_interaction_mode);
  fTree->Branch("nu_interaction_type", &nu_interaction_type);
  fTree->Branch("nu_CC_NC", &nu_CC_NC);
  fTree->Branch("nu_target", &nu_target);
  fTree->Branch("nu_HitNuc", &nu_HitNuc);
  fTree->Branch("nu_HitQuark", &nu_HitQuark);
  fTree->Branch("nu_W", &nu_W);
  fTree->Branch("nu_X", &nu_X);
  fTree->Branch("nu_Y", &nu_Y);
  fTree->Branch("nu_QSqr", &nu_QSqr);  
  fTree->Branch("gen_index", &gen_index);

  //MCTruth Particles variables
  fTree->Branch("gen_part_trackID", &gen_part_trackID);
  fTree->Branch("gen_part_statusCode", &gen_part_statusCode);
  fTree->Branch("gen_part_mother", &gen_part_mother);
  fTree->Branch("gen_part_PDGcode", &gen_part_PDGcode);
  fTree->Branch("gen_part_mass", &gen_part_mass);
  fTree->Branch("gen_part_E0", &gen_part_E0);
  fTree->Branch("gen_part_start_pos_X", &gen_part_start_pos_X);
  fTree->Branch("gen_part_start_pos_Y", &gen_part_start_pos_Y);
  fTree->Branch("gen_part_start_pos_Z", &gen_part_start_pos_Z);
  fTree->Branch("gen_part_P0_X", &gen_part_P0_X);
  fTree->Branch("gen_part_P0_Y", &gen_part_P0_Y);
  fTree->Branch("gen_part_P0_Z", &gen_part_P0_Z);

  //Geant4 Particles variables
  fTree->Branch("g4_part_trackID", &g4_part_trackID);
  fTree->Branch("g4_part_mother", &g4_part_mother);
  fTree->Branch("g4_part_PDGcode", &g4_part_PDGcode);
  fTree->Branch("g4_part_mass", &g4_part_mass);
  fTree->Branch("g4_part_E0", &g4_part_E0);
  fTree->Branch("g4_part_Ef", &g4_part_Ef);
    
  fTree->Branch("g4_part_start_pos_X", &g4_part_start_pos_X);
  fTree->Branch("g4_part_start_pos_Y", &g4_part_start_pos_Y);
  fTree->Branch("g4_part_start_pos_Z", &g4_part_start_pos_Z);
  fTree->Branch("g4_part_end_pos_X", &g4_part_end_pos_X);
  fTree->Branch("g4_part_end_pos_Y", &g4_part_end_pos_Y);
  fTree->Branch("g4_part_end_pos_Z", &g4_part_end_pos_Z);

  fTree->Branch("g4_part_P0_X", &g4_part_P0_X);
  fTree->Branch("g4_part_P0_Y", &g4_part_P0_Y);
  fTree->Branch("g4_part_P0_Z", &g4_part_P0_Z);
  fTree->Branch("g4_part_Pf_X", &g4_part_Pf_X);
  fTree->Branch("g4_part_Pf_Y", &g4_part_Pf_Y);
  fTree->Branch("g4_part_Pf_Z", &g4_part_Pf_Z);
  
  fTree->Branch("g4_part_process", &g4_part_process);
  fTree->Branch("g4_part_end_process", &g4_part_end_process);

}



void test::AnalyzeEventsTruth::endJob()
{
  // Implementation of optional member function here.
}

DEFINE_ART_MODULE(test::AnalyzeEventsTruth)
