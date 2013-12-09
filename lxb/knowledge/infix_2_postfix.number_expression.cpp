string infix_2_postfix(const string infix)
{
  stack<char> op;
  string res;
  for (auto ch:infix){
    switch(ch){
	case '(':
		op.push(ch);
		break;
	case ')':
		while (!op.empty() && op.top() != '('){
			res += op.top(); 
			op.pop();
		}
		break;
	case '*':
		if (op.empty() || op.top() == '(')){
			op.push(ch);
		}else{
			res += '*';
		}
		break;
	case '+':
		if (op.empty() || op.top() !='*'){
			op.push('+');
		}else{
		  while (!op.empty() && op.top() == '*'){
			res += op.top();
			op.pop();
		  }
		  op.push('+');
		}
		break;
	default:
		res += ch;
    }
   }

   while(!op.empty()) {res += op.top(); op.pop();}

   return res;
 }

//test case: (1+2)*3+4*5
//expected postfix: 1 2 + 3 * 4 * 5 +
// evaluate postfix.
