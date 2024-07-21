char sign;
            cin>>sign;
            ll num; cin>>num;
            if(sign=='+'){
                
                dpmax[i]=max(dpmax[i-1]+num,dpmax[i-1]);
                dpmin[i]=min(dpmin[i-1]+num,dpmin[i-1]);
            }else if(sign=='-'){
                dpmax[i]=max(dpmax[i-1]-num,dpmax[i-1]);
                dpmin[i]=min(dpmin[i-1]-num,dpmin[i-1]);
            }else if(sign=='*'){
                dpmax[i]=max(dpmax[i-1]/num,dpmax[i-1]);
                dpmin[i]=min(dpmin[i-1]/num,dpmin[i-1]);               
            }else if(sign =='/'){
                dpmax[i]=max(dpmax[i-1]/num,dpmax[i-1]);
                dpmin[i]=min(dpmin[i-1]/num,dpmin[i-1]);
            }else{
                dpmax[i]=max(-1*dpmin[i-1],-1*dpmax[i-1]);
                dpmin[i]=min(-1*dpmax[i-1],-1*dpmin[i-1]);                
            }