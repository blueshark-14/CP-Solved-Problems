class Solution {
    /// trie implement
    struct node{
        node *next[26];
        string word;      
        node()
        {
            word="";
            for(int i=0; i<26; i++)
                next[i]=NULL;    
        }       
    }*root;
    /// insert
    void insert(string s){
        
        node *curr = root;
        for(int i=0; i<s.size(); i++){
            int id = s[i]-'a';
            if(curr->next[id] == NULL)
                curr->next[id] = new node();
            
            curr=curr->next[id];
        }
        curr->word = s;
    }
    /// delete
    void del(node *curr){
        for(int i=0; i<26; i++)
            if(curr->next[i]!=NULL)
                del(curr->next[i]);
        delete(curr);
    }   
    ///dfs 
    void dfs(vector<vector<char>>& board, int i, int j, node *curr , vector<string>&res ){
        
        char c=board[i][j];
        int id = c-'a';
        if(c == '#'  || curr->next[id] == NULL) return ;
       
        curr = curr->next[id] ;
        
        if(curr->word != ""){
            res.push_back(curr->word);
            curr->word="";
        }
        
        board[i][j]='#';
        
        if (i > 0) dfs(board, i - 1, j ,curr, res); 
        if (j > 0) dfs(board, i, j - 1, curr, res);
        if (i < board.size() - 1) dfs(board, i + 1, j, curr, res); 
        if (j < board[0].size() - 1) dfs(board, i, j + 1, curr, res); 
        
        board[i][j] = c;
    }
   
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        vector<string>res;
        root = new node();
        
        for(int i=0; i<words.size(); i++)
            insert(words[i]);
        for(int i=0; i<board.size(); i++){
           for(int j=0; j<board[0].size(); j++){
               dfs(board, i, j , root, res);
           }
        } 
        del(root);
        return res;
    }
};
