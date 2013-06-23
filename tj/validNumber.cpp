class Solution {
private:
    enum {
        INTEGER = 0,
        FLOAT = 1,
        EXPSTART = 2,
        EXP = 3,
        TRAILING = 4,
        INVALID = 5
    };
    
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int state = INTEGER;       
        const char * p =s;
        while(*p == ' ') p++;
        if ( *p == NULL) return false; //BUG: missing this scenario
        if ( *p == '+' || *p == '-') p++;
        if ( *p == NULL) return false; //BUG: missing this scenario
        bool integerPart = false;
        bool floatPart = false;
        bool expPart = false;
        bool isFloat = false;
        bool isExp = false;
        while(*p) {
            if ( isdigit(*p)) {
                switch( state) {
                    case INTEGER:
                        integerPart = true;
                        break;
                    case FLOAT:
                        floatPart = true;
                        break;
                    case EXP:
                    case EXPSTART:
                        expPart = true;
                        break;
                }
            }                        
            state = transfer(state, *p);
            if ( state == INVALID) {
                return false;
            }
            if ( state == FLOAT) {
                isFloat = true;
            }
            else if ( state == EXPSTART) {
                isExp = true;
            }
            ++p;
        }
        if ( isExp && !expPart ) return false;
        if ( isFloat && !floatPart && !integerPart) return false;
        if ( !integerPart && !floatPart) return false;
        return true;
    }
    
    int transfer(int state, char ch) {
        switch(state) {
            case INTEGER:
                if ( isdigit(ch)) {
                    return INTEGER;
                }
                else if ( ch == '.') {
                    return FLOAT;
                }
                else if ( ch == 'e' || ch == 'E') {
                    return EXPSTART;
                }
                else if ( ch == ' ') {
                    return TRAILING;
                }
                else {
                    return INVALID;
                }
            case FLOAT:
                if ( isdigit(ch)) {
                    return FLOAT;
                }
                else if ( ch == 'e' || ch == 'E') {
                    return EXPSTART;
                }
                else if ( ch == ' ') {
                    return TRAILING;
                }
                else {
                    return INVALID;
                }
            case EXPSTART:
                if ( isdigit(ch) || ch == '+' || ch == '-' ) {
                    return EXP;
                }
                else {
                    return INVALID;
                }
            case EXP:
                if ( isdigit(ch)) {
                    return EXP;
                }
                else if ( ch == ' ') {
                    return TRAILING;
                }
                else {
                    return INVALID;
                }
            case TRAILING:
                if ( ch == ' ') {
                    return TRAILING;
                }
                else {
                    return INVALID;
                }
            default:
                return INVALID;
        }
    }
};