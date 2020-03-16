# How to use this Blog Engine

When I began this project I wanted to start a programming blog, but found most of the
frameworks to be overly complicated or have features I did not want or need. Maybe I just
wanted an excude to learn ReasonML ✨.

## Get started

Install node v10

```
yarn
```

```
touch .env
```

Add your aws keys

```
# .env
AWS_ACCESS_KEY=
AWS_SECRET=
BUCKET_NAME=
```

```
cd posts
touch Welcome.md
```

posts.json looks like

```
[
  {
    "id": "1",
    "file": "Welcome.md",
    "title": "Welcome"
  }
]
```

[Welcome.md can be any markdown.](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet)

to make your posts public run

```
yarn run add-posts
```

This will upload all your posts to s3

## Run project locally

```
yarn run start
```

```
yarn run server
```

## Deploy changes to code base

```
yarn run publish
gaa
git commit -m"publish"
git push
```

Configure github pages to use the master branch.

[Working example: this blog's codebase](https://github.com/jottenlips/jottenlips.github.io)
