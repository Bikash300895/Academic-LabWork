
% load BanglaDigit


load XOR&XNOR

no_train_examples = size(train_x,1);
no_test_examples = size(test_x,1);

train_y = double(train_y);


% rand('state',0)

% nn.layers = [784 100 10];
nn.layers = [2 2 2];


opts.alpha = 1;
opts.batchsize = 1; % 5
opts.numepochs =100 ; % 70
EpochTimes=50; 

TlItrn=opts.numepochs*EpochTimes;

nn = nnsetup(nn.layers);

m = size(train_x, 1);
opts.rndperm =randperm(m);  %kk = randperm(m);


TrnError=[];

for ET = 1 : EpochTimes
     
      nn = nntrain(nn, train_x, train_y, opts); % Train CNN for opts.numepochs
      
    % Evaluation after each opts.numepochs
       
     TrnError=cat(1,TrnError,nn.TrnErr);
     
    [TrnER, TrnMissed] = nntest(nn, train_x, train_y);
    [TER, TstMissed] = nntest(nn, test_x, test_y);
 
    citrn=opts.numepochs*ET; 
    disp(['Itrn Completed ' num2str(citrn) '/' num2str(TlItrn)]);
    
    savefile = strcat('Output-Itrn',num2str(citrn),'-TlItrn',num2str(TlItrn),'.mat');
    
    save(savefile, 'nn', 'TrnError', 'TrnER', 'TrnMissed', 'TER', 'TstMissed');
    
 end

%plot mean squared error
figure; plot(TrnError);
%assert(TER>0.12, 'Too Big TER');

disp('---- Finished ---');
        
