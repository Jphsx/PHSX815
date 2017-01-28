 %computes chisq probability density function with value x (only singular
%value x because laziness) and ndf=v
function p = chisqpdf(x,v)
p = (x.^((v/2)-1) .* exp(-x./2)) ./ ( 2^(v/2) * gammaFun(v));
end