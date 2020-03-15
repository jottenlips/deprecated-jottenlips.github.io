# ReasonML Markdown Blog Engine

## Get started

Install node v10

```
yarn
```

```
touch .env
```

Add aws keys

```
# .env
AWS_ACCESS_KEY=
AWS_SECRET=
```

```
mkdir posts
touch posts.json
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

Welcome.md can be any read me.

to make your posts public run

```
yarn run add-posts
```

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
