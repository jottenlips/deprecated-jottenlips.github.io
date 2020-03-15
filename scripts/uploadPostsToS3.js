const fs = require("fs");
const AWS = require("aws-sdk");
require("dotenv").config();

const s3 = new AWS.S3({
  accessKeyId: process.env.AWS_ACCESS_KEY,
  secretAccessKey: process.env.AWS_SECRET
});

const folder = "./posts";

const uploadFile = () => {
  const files = fs.readdirSync(folder);
  files.map(file => {
    fs.readFile(`${folder}/${file}`, (err, data) => {
      if (err) throw err;
      const params = {
        Bucket: `jottenlips.github`, // pass your bucket name
        Key: `posts/${file}`, // file will be saved in <folderName> folder
        Body: data
      };
      s3.upload(params, (error, data) => {
        if (error) throw err;
        console.log(`${data.Location} uploaded to s3`);
      });
    });
  });
};

uploadFile();
