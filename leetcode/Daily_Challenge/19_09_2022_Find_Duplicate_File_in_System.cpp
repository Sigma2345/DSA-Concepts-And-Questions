// https://leetcode.com/problems/find-duplicate-file-in-system/

/*
  the concept is :
  -> first find common route till the first blank (main common root of files in the string)
  -> then get the name of the specific file (get all the characters till '(' ) --> this is subpath
  -> then get the name of the mapping as string (mapper)
  -> then map the route to the mapper in unordered_map
  
  -> while traversing map , consider only  mapper where more than one route is mapped to get duplicates
*/


class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
      unordered_map<string , vector<string> > mp  ; 
        for(int i = 0 ;  i<paths.size() ; i++){
            
            int it = 0; 
            //first get root path 
            while(paths[i][it]!=' ') it++ ; 
            string main = paths[i].substr(0,it); 
            it++ ; 
            
            for(int j = it ; j<paths[i].length(); j++){
                //get path before bracket
                int k = j ; 
                while(paths[i][k]!='('){
                    k++ ;
                } 
                string subpath = paths[i].substr(j,k-j);
                
                //get mapper
                k++; 
                j = k ; 
                while(paths[i][k]!=')'){
                    k++ ;
                } 
                string mapper = paths[i].substr(j,k-j);
                k++;
                j=k;
                
                string finalstr = main + "/" + subpath ; 
                mp[mapper].push_back(finalstr);
            }
        }
        vector < vector<string> > ans;
        for(auto x: mp){
            vector<string> s ;
            if(x.second.size()>1){
                for(auto child : x.second){
                    s.push_back(child) ;
                }        
                ans.push_back(s) ;
            }
        }    
        return ans ; 
    }
};
