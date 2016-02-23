
%code snagged an modified from:
%http://www.matrixlab-examples.com/factorials.html
function df = dubFactorial(n)
df = 1;
for i = n : -2 : 1
    df = df * i;
end
end