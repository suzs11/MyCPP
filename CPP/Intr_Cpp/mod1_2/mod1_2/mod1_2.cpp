/*
 *   mod version 1.2, release date 04/13/2017
 *   Copyright 2014 Pan Zhang ( pan@santafe.edu )
 *	 Modified by Cheng Shi (shicheng1995@hotmail.com)
 *   mod is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or 
 *   (at your option) any later version.

 *   sbm is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
*/
//{{{header files
#include "bm.h"
//}}}

	//{{{void show_help_short()
	void show_help_short(char **argv)
	{
		cout<<"Modularity and data clustering in weighted graph"<<endl;
		cout<<"Usage: "<<argv[0]<<" [infer/retrieval/select/hiera] options. For more information, try "<<argv[0]<<" -h"<<endl;
		exit(0);
	}
	//}}}
//{{{void show_help()
void show_help(char **argv)
{
	string deli(" ");
	cout<<"Community detection and hierarchical clustering by message passing"<<endl;
	cout<<"Usage: "<<argv[0]<<" [infer/retrieval/select/hiera] options"<<endl;
	cout<<"Options:"<<endl;
	cout<<" -l: set lfname, name of Graph file"<<endl;
	cout<<" -L: set lfname, name of spm file"<<endl;
	cout<<" -k: set the type of the graph, 0 is for unweighted, 1 is for weighted graph, default 0."<<endl;
	cout<<" -R: set dumping_rate, from 0.0 to 1.0. The larger value, the faster converge. default 1.0(no dumping)."<<endl;
	cout<<" -e: set bp_conv_crit, convergence criterium of BP, from 0.0 to 1.0. Default 1.0e-6."<<endl;
	cout<<" -t: set time_conv, maximum time for BP to converge, default 100."<<endl;
	cout<<" -q: set Q, number of communities, default 2."<<endl;
	cout<<" -D: set randseed, default value is set from current time, which changes every call."<<endl;
	cout<<" -v: set verbose flag, valid values are -1, 0, 1, 2, 3. Larger value gives more output message. Default 0."<<endl;
	cout<<" -w: set gml_fname, name of file to write graph in gml format."<<endl;
	cout<<" -l: if use -l temp.gml as the filename , it will use the SBM example network with -a for average degree and -n for groups"<<endl;
	
	cout<<" -h: show help and exit"<<endl;
	cout<<endl<<"Examples:"<<endl;
	cout<<"Modular detection on unweighted graph a.gml, by modularity-BP using beta=1.35: "<<endl;
	cout<<deli<<argv[0]<<" infer -l a.gml -k0 -q4 -b1.35 -v1"<<endl;
	cout<<"Modular retrieval on weighted graph a.gml, by finding a retrieval state: "<<endl;
	cout<<deli<<argv[0]<<" infer -l a.gml -k1 -q4"<<endl;
	cout<<"Select number of groups"<<endl;
	cout<<deli<<argv[0]<<" select -l a.gml "<<endl;;
	cout<<"Find hierarchical structure "<<endl;
	cout<<deli<<argv[0]<<" hiera -l a.gml "<<endl;
	cout<<"Modular detection on the sample weighted graph, SBM graph in 3 groups with average degree as 8."<<endl;
	cout<<deli<<argv[0]<<" infer -l temp.gml -a8 -n3 -k1 -q3 "<<endl;
	exit(0);
}
//}}}
void parse_command_line(int argc, char **argv, string & lfname, double &dumping_rate, double &bp_conv_crit, int &time_conv, double &al, int &Q,int &wf, int &randseed, int &vflag, int &LARGE_DEGREE, string &fconfi, double &beta, int &exn, bool &averr, bool &opt, string &gml_fname, string &spm_fname)
{
	static struct option long_options[] =
	{
		{"help",     no_argument,       0, 'h'},
		{"load",  required_argument, 0, 'l'},
		{"loadspm",  required_argument, 0, 'L'},
		{"verbose",    required_argument, 0, 'v'},
		{"drate",    required_argument, 0, 'R'},
		{"bperr",    required_argument, 0, 'e'},
		{"tconv",    required_argument, 0, 't'},
		{"q",    required_argument, 0, 'q'},
		{"seed",    required_argument, 0, 'D'},
		{"ld",   required_argument, 0, 20},
		{"confi",    required_argument, 0, 37},
		{"beta",    required_argument, 0, 'b'},
		{"averr",    no_argument, 0, 39},
		{"opt",    no_argument, 0, 48},
		{"write",    required_argument, 0, 'w'},
		{"wf",    required_argument, 0, 'k'},
		{"al",    required_argument, 0, 'a'},
		{"exn",    required_argument, 0, 'n'},
		{0, 0, 0, 0}
	};
	int option_index = 0;
	char cc;
	while((cc=getopt_long(argc,argv,"l:r:R:e:E:t:q:D:v:s:L:c:I:T:p:P:i:m:n:w:W:v:d:M:A:b:g:fh:k:a:n",long_options,&option_index))!=-1){
	  switch(cc){
			case 'l':	lfname=optarg;	break;
			case 'L':	spm_fname=optarg;	break;
			case 'v':	vflag=atoi(optarg); break;
			case 'R':	dumping_rate=atof(optarg); break;
			case 'e':	bp_conv_crit=atof(optarg); break;
			case 't':	time_conv=atoi(optarg); break;
			case 'q':	Q=atoi(optarg); break;
			case 'D':	randseed=atoi(optarg); break;
			case 20:	LARGE_DEGREE=atoi(optarg); break;
			case 37:	fconfi=optarg; break;
			case 39:	averr=true; break;
			case 'b':	beta=atof(optarg); break;
			case 48:	opt=true; break;
			case 'w':	gml_fname=optarg;	break;
			case 'k':	wf=atoi(optarg);	break;
			case 'n':	exn=atoi(optarg);	break;
			case 'a':	al=atof(optarg);	break;
			case 'h':	show_help(argv);
		}
	}
}
//}}}

//{{{ int main(int argc, char** argv)
int main(int argc, char** argv)
{
	//read the first argument to set the function.
	if(argc==1) show_help_short(argv);
	string function;
	if(argc > 1){
		function=argv[1];
		if(function == string("-h")||function == string("--help")) show_help(argv);
		else if(function != string("infer") && function != string("findsg")&& function != string("retrieval")&& function != string("select")&& function != string("hiera") && function != string("hiera2")&& function != string("spectral")) show_help_short(argv);
	}

	//set other parameters
	double dumping_rate=1.0;//dumping rate
	double bp_conv_crit=1.0e-6;//convergence criterion of BP
	double beta=-200.0;
	double al=2; // inverse temperature
	bool averr=false;//averr = true will triger average interating error instead of maximum error in BP iteration.
	long t_begin=get_cpu_time();
	int time_conv=1000; //maximum time for BP to converge
	int	Q=2; // number of groups that will be used in BP
	int wf=0; //unweighted
	int	randseed=0; // seed of random number generator.
	int vflag=0; // verbose flag
	int LARGE_DEGREE=51; // if degree of node is larger than LARGE_DEGREE, bp update function will be changed to a more robust one.
	bool opt=false;
	int exn=2;//optimize modularity in retrieval

	string lfname; // filename to load
	string lfname_spm; // spm filename to load
	string gml_fname; // filename to write graph and inferred configuration (in gml format)
	string fconf_infer; //filename to store inferred configuration
	char **myargv;
	myargv=new char *[argc-1];
	myargv[0]=new char[1024];
	strcpy(myargv[0],argv[0]);
	for(int i=1;i<argc-1;i++){
		myargv[i]=new char[1024];
		strcpy(myargv[i],argv[i+1]);
	}

	






	parse_command_line(argc, argv, lfname, dumping_rate, bp_conv_crit, time_conv, al, Q, wf, randseed, vflag, LARGE_DEGREE,fconf_infer,beta,exn,averr,opt,gml_fname,lfname_spm);
	
	
	if(randseed<=0) randseed=int(time(NULL));
	cout<<"filename="<<lfname<<" dumping_rate="<<dumping_rate<<" bp_conv_crit="<<bp_conv_crit<<" time_conv="<<time_conv<<" Q="<<Q<<" randseed="<<randseed<<" vflag="<<vflag<<" wf="<<wf<<endl;
	ZRANDOMv3 rg(randseed);
	//generate sample network
	if (lfname=="temp.gml"){
	cout<<"using SBM network with average degree of "<<al<<" in "<<exn<<" groups"<<endl;
		int ssize=10000;
		int hsize=ssize/exn+1;
		double alpha=4;
		alpha=al;
		int negde=ssize*al/2;
		string fname1="temp.gml";
		ofstream fout(fname1.c_str());
		fout<<"graph"<<endl;
		fout<<"["<<endl;
		int xi=0;		
		
		do{
			fout<<"node"<<endl;
			fout<<"["<<endl;
			fout<<"id"<<" "<<xi<<endl;
			fout<<"value"<<" "<<int(xi/hsize)<<endl;
			fout<<"]"<<endl;
			xi++;
		}while(xi<ssize);
		for(int i=0;i<negde;i++){
			long rrrm =rg.rdflt()*ssize*ssize;
			xi=rrrm/ssize;
			int xj=rrrm%ssize;
			
			fout<<"edge"<<endl;
			fout<<"["<<endl;
			fout<<"source"<<" "<<xi<<endl;
			fout<<"target"<<" "<<xj<<endl;
			if (wf==0) fout<<"weight"<<" "<<1<<endl;
			else{
				if ((int(xi/hsize))==(int(xj/hsize))) fout<<"weight"<<" "<<rg.gasdev()+0.75<<endl;
				else fout<<"weight"<<" "<<rg.gasdev()-0.75<<endl;
			}

			fout<<"]"<<endl;


		} 





	}



	modbp bm(&rg, LARGE_DEGREE, bp_conv_crit, Q, wf, vflag, beta, averr, opt);
	if(!lfname.empty()) bm.graph_read_graph(lfname);
	else if(!lfname_spm.empty()) bm.graph_read_graph_spm(lfname_spm);
	else{
		cerr<<"You have to specify a network file (gml format) by -l (gml) or -L (spm, edge list) parameter."<<endl;
		exit(1);
	}

	if(function == string("infer")){ // inference
		bm.do_inference( bp_conv_crit, time_conv, dumping_rate);
		if(!fconf_infer.empty()) bm.mod_record_conf_infer(fconf_infer);
		bm.output_group_sizes();
	}else if(function == string("retrieval")){ // find the retrieval state
		bm.retrieval(bp_conv_crit, time_conv, dumping_rate,1);
		bm.output_group_sizes();
		bm.output_f_ovl(1);
		if(!fconf_infer.empty()) bm.mod_record_conf_infer(fconf_infer);
	}else if(function == string("findsg")){ // find spin glass transition
		bm.sg(bp_conv_crit, time_conv, dumping_rate,1);
	}else if(function == string("select")){ // model selection on number of groups
		bm.select(bp_conv_crit, time_conv, dumping_rate,1);
		if(!fconf_infer.empty()) bm.mod_record_conf_infer(fconf_infer);
	}else if(function == string("hiera")){ //hierarchical clustering 
		bm.hiera(bp_conv_crit, time_conv, dumping_rate,1);
		if(!fconf_infer.empty()) bm.mod_record_conf_infer(fconf_infer);
	}else if(function == string("spectral")){// spectral and generate the non——backtracking 
		bm.spectral(bp_conv_crit, time_conv, dumping_rate,1);
		
	}else{
		show_help(argv);
	}
	if(function != string("findsg")){
		if(!gml_fname.empty()) bm.graph_write_gml_infer(gml_fname.c_str());
	}
	cout<<"time used: "<<(get_cpu_time()-t_begin)/1000.0<<" seconds."<<endl;
}
//}}}

