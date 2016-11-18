{
    //////////////////////////////////////////////
    //        Choose between BTag or CTag      //
    /////////////////////////////////////////////         
    bool BTag = true; //false for CTag commissioning

    // Options for CommPlotProducer4ttbar::Loop
    TString syst="";

    //////////////////////
    //BTag Commissioning//
    /////////////////////
    if(BTag){
    //set the range of ntuples to run on (iname[Nsamples])
    const int j=7;
    const int k=7;    

    // Samples defination
    //Data13TeV_MuonEG_2016B
    //MC13TeV_DY10to50
    //MC13TeV_DY50toInf
    //MC13TeV_SingleT_tW
    //MC13TeV_SingleTbar_tW
    //MC13TeV_TTJets_powheg_pythia8
    //MC13TeV_WW
    //MC13TeV_WZ
    //MC13TeV_ZZ
    //
    const int Nsamples=10;
    TString iname[Nsamples] = { 
                                //"Data13TeV_MuonEG_2016B",       // 0
                                //"Data13TeV_MuonEG_2016B_589pb", // 0
                                //"Data13TeV_MuonEG_2016B_804pb",  // 0
                                //"Data13TeV_MuonEG_2016B_2fb",  // 0
                                "Data13TeV_MuonEG_2016B_6fb",  // 0
                                "Data13TeV_MuonEG_2016C_6fb",  // 1
                                "MC13TeV_TTJets_powheg_pythia8", // 2
                                "MC13TeV_DY10to50",              // 3
                                "MC13TeV_DY50toInf",             // 4
                                "MC13TeV_SingleT_tW",            // 5
                                "MC13TeV_SingleTbar_tW",         // 6
                                "MC13TeV_WW",                    // 7
                                "MC13TeV_WZ",                    // 8 
                                "MC13TeV_ZZ"                     // 9
                                }; 
    TString oname[Nsamples] = { "output_dataB_mueg",
                                "output_dataC_mueg",
                                "output_ttbar",
                                "output_dy1",
                                "output_dy2",
                                "output_st1",
                                "output_st2",
                                "output_ww",
                                "output_wz",
                                "output_zz" 
                                };
 
    //float sf_dy=1.3; // in Run2015
    float sf_dy=1;
    bool isData[Nsamples] = {1, 1, 0, 0, 0, 0, 0, 0, 0, 0 }; 

    TString samplepath="root://eoscms.cern.ch//eos/cms/store/user/jtsai/btag/HIPMitigation/final/HIP";
    TString sampleroot="MergedJetTree.root";

    ///////////////////
    // Main Loop    //
    //////////////////
    for (int i=j; i<k+1; i++) { 
    // Run... 
    TFile* f = TFile::Open(samplepath+"/"+iname[i]+"/"+sampleroot);
    TChain* tree = (TChain*)f->Get("btagana/ttree");
    CommPlotProducer4ttbar *run = new CommPlotProducer4ttbar(tree,1,1,0);

    if( !isData[i] )
    {
        TH1F* inputWeight = (TH1F*)f->Get("ttbarselectionproducer/wgtcounter");
        run->Loop( isData[i], oname[i], inputWeight, syst);
    }
    else
    {
        run->Loop( isData[i], oname[i], 0, syst);
    }
    }//end for loop

    } // end BTag commissioning

    //////////////////////
    //CTag Commissioning//
    /////////////////////
    if(!BTag){
    const int j=7;
    const int k=7;

    const int Nsamples=20;
    TString iname[Nsamples] = {
                                "Data13TeV_Mu_2016B", //0
                                "Data13TeV_Mu_2016C", //1
                                "Data13TeV_Mu_2016D", //2
                                /*"Data13TeV_Elec_2016B", //0"
                                "Data13TeV_Elec_2016C", //1
                                "Data13TeV_Elec_2016D", //2      
                                */"MC13TeV_TTJets_powheg_pythia8_1", //3
                                "MC13TeV_DY", //4
                                "MC13TeV_SingleT_s-channel", //5
                                "MC13TeV_SingleT_tW", //6
                                "MC13TeV_SingleTbar_t-channel", //7
                                "MC13TeV_SingleTbar_tW", //8
                                "MC13TeV_WJets", //9
                                "MC13TeV_QCD_Pt-30to50_MuEnrichedPt5", //10
                                "MC13TeV_QCD_Pt-50to80_MuEnrichedPt5", //11
                                "MC13TeV_QCD_Pt-80to120_MuEnrichedPt5", //12
                                "MC13TeV_QCD_Pt-120to170_MuEnrichedPt5", //13
                                "MC13TeV_QCD_Pt-170to300_MuEnrichedPt5", //14
                                "MC13TeV_QCD_Pt-300to470_MuEnrichedPt5", //15
                                "MC13TeV_QCD_Pt-470to600_MuEnrichedPt5", //16
                                "MC13TeV_QCD_Pt-600to800_MuEnrichedPt5", //17
                                "MC13TeV_QCD_Pt-800to1000_MuEnrichedPt5", //18
                                "MC13TeV_QCD_Pt-1000toInf_MuEnrichedPt5" //19
                                /*"MC13TeV_QCD_Pt-30to50_EMEnriched", //10
                                "MC13TeV_QCD_Pt-50to80_EMEnriched", //11
                                "MC13TeV_QCD_Pt-80to120_EMEnriched", //12
                                "MC13TeV_QCD_Pt-120to170_EMEnriched", //13
                                "MC13TeV_QCD_Pt-170to300_EMEnriched", //14
                                "MC13TeV_QCD_Pt-300toInf_EMEnriched" //15
                                */};
    TString oname[Nsamples] = { "output_MUdataB_mueg",
                                "output_MUdataC_mueg",
                                "output_MUdataD_mueg",
                                /*"output_ElecdataB_mueg",
                                "output_ElecdataC_mueg",
                                "output_ElecdataD_mueg",        
                                */"output_ttbar",
                                "output_dy",
                                "output_st_s",
                                "output_st_tW",
                                "output_stbar_t",
                                "output_stbar_tW",
                                "output_wjets",
                                "output_qcd_mu30to50",
                                "output_qcd_mu50to80",
                                "output_qcd_mu80to120",
                                "output_qcd_mu120to170",
                                "output_qcd_mu170to300",
                                "output_qcd_mu300to470",
                                "output_qcd_mu470to600",
                                "output_qcd_mu600to800",
                                "output_qcd_mu800to1000",
                                "output_qcd_mu1000toinf"
                                /*"output_qcd_em30to50",
                                "output_qcd_em50to80",
                                "output_qcd_em80to120",
                                "output_qcd_em120to170",
                                "output_qcd_em170to300",
                                "output_qcd_em300toInf" 
                                */};

    //float sf_dy=1.3; // in Run2015
    float sf_dy=1; //https://indico.cern.ch/event/557018/contributions/2246861/attachments/1310556/1960899/btag_ttbar_sf_17-07-2016.pdf
    bool isData[Nsamples] = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    //int isData[Nsamples] = {0, 0, 0, 1, 2, 3, 3, 3, 3, 4, 5, 5, 5, 5, 5, 5 }; 
    //float xsec[Nsamples]   = {0, 0, 0, 831.77, 6024*sf_dy, 3.4, 35.6, 72.3, 35.6, 61524, 9928000, 2890800, 350000, 62964, 18810, 135 };

    TString samplepath="/eos/uscms/store/user/kovitang/July30_v0";
    TString sampleroot="MergedJetTree.root";

    ///////////////////
    // Main Loop    //
    //////////////////
    for (int i=j; i<k+1; i++) { 
    // Run... 
    TFile* f = TFile::Open(samplepath+"/"+iname[i]+"/"+sampleroot);
    TChain* tree = (TChain*)f->Get("btagana/ttree");
    CommPlotProducer4ttbar *run = new CommPlotProducer4ttbar(tree,0,0,1);

    if( !isDate[i] )
    {
        TH1F* inputWeight = (TH1F*)f->Get("ttbarselectionproducer/wgtcounter");
        run->Loop( isData[i], oname[i], inputWeight, syst);
    }
    else
    {
        run->Loop( isData[i], oname[i], 0, syst);
    }
    }//end for loop

    }//end CTag commissioning
}
