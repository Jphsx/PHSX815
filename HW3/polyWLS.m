
function [B,Yhat] = polyWLS(X,Y,sigma_Y,deg)
    %format X which is passed in as nx1 matrix
    %x-> vandermonde matrix of degree deg
    for i=0:(deg)
        X = [X , X(:,1).^i ]; 
    end
    %cut out first column so matrix follows proper degree
    X = X(:,2:end);
    %format nx1 weight matrix W to diagonal nxn
    W = diag(sigma_Y);
   %Mimizing least squares L2 Norm yields Beta vector px1 
   B = inv(X'*W'*W*X)*X'*W'*W*Y;
    %get the model estimates for Y with the minimized Beta vector
   Yhat = X*B;
   %pad B with zeros to be returned with Y model estimate
   B = [ B; zeros(size(Yhat,1)-size(B,1),1)];
end

