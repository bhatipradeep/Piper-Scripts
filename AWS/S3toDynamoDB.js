console.log('Loading function');

//do install aws-sdk and csvtojson using npm install
const aws = require('aws-sdk');
const csv = require('csvtojson');

//Note: If you are writing this code on lambda then no need to set Credentials
//Note: For local machine you can refer below for setting credentials:
//https://docs.aws.amazon.com/sdk-for-javascript/v2/developer-guide/setting-credentials-node.html 

aws.config.update({region: 'YOUR_REGION'});
const S3 = new aws.S3();
const ddb = new aws.DynamoDB({
    apiVersion: '2012-08-10',
});

exports.handler = async (event) => {

    //details about csv file in s3
    var params = {
        Bucket:"BUCKET_NAME",
        Key:"FILE_NAME"
    }

    //create a Nodejs stream
    const stream = S3.getObject(params).createReadStream();
    
    //convert csv to json through Nodejs stream
    const json = await csv().fromStream(stream);
    

    //here json will be a sample JSON of n size
    //sample json[0] = {
    //     "data-1":"abc",
    //     "data-2":"cde",
    //     "data-3": 123   
    // }
    //sample dynaodbTable have 3 columns - COLUMN-1,COLUMN-2,COLUMN-3

    for(var i=0;i<json.length;i++){

        var jsonElement = json[i];
        var params = {
            TableName: 'DYNAMODB_TABLE_NAME',
            Item: {
              'COLUMN_1' : {S: jsonElement["data-1"]},
              'COLUMN_2' : {S: jsonElement["data-2"]},
              'COLUMN_3' : {N: jsonElement["data-3"]}
            }
        };
        
        // Call DynamoDB to add the item to the table
        ddb.putItem(params, function(err, data) {
            if (err) {
            console.log("Error", err);
            } else {
            console.log("Success", data);
            }
        });
    }    
};
//comment below line if code runs in aws lambda
exports.handler();
