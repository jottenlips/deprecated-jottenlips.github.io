type content = {
    format: string,
    text: string
};

type post = {
    id: string,
    title: string,
    content: list(content)
  };

let posts =  [{
    id: "0",
    title: "Function Junction, Day 1: Lets write some JS.",
    content: [{
        format: "p",
        text: "
        I get asked a lot from friends and family with some or no programming experience what it takes to becoming a developer. A lot of times they may have taken a programming class in college or done a handful of tutorials online but do not have a direction or plan after that.  This post is for everyone out there who wants to get into making software. Since I primarily do full-stack web development, and this is a very approachable point of entry into the software world, I will be focusing on that. These \"days\" can be done back to back or have a few days in-between. I am grouping them into days for the sake of organization. It is best to do a small bit day by day than to do a large amount of work once a week. I will be using a Mac for this tutorial.

        Here is a list of tools for getting started.

        >- The terminal app
        >- homebrew, follow the install guide https://brew.sh
        >- node and NPM
        >- Your favorite text or code editor, sublime text or vscode for me"
    }, {
        format: "code",
        text: "
        brew install node # installs node and npm"
    },{
        format: "p",
        text: "
        Install a text editor."
    },{
        format: "code",
        text: "
        brew install node # installs node and npm
        brew install caskroom/cask/brew-cask # install installer for apps
        brew tap caskroom/versions
        brew cask install sublime-text # install Sublime Text application" 
    }, {
        format: "p", 
        text:"or https://code.visualstudio.com/Download (I use this at work)"
    }, {
        format: "code",
        text: "
        mkdir programming // makes a folder called programming, you can name this whatever you\'d like.
        cd programming // changes directory so that you will be in your programming directory.
        touch mynewfile.js // create a file named mynewfile.js.
        "
    }, { 
        format: "p", 
        text: "Let\'s write our first function."
    }, {
        format: "code",
        text: "
        // Functions can be as easy as add.
        const add = (x, y) =>  x + y
        // shorthand for
        const add = (x, y) => {
            return x + y
        }
        
        const sum = add(1,2)
        console.log(sum) // 3
        "
    }, {
        format: "p",
        text: "
        Think of a topic that interests you. I love music theory so I am going to write a simple function that tells me the fifth of any note.
        Here is the code!        
        "
    }, {
        format: "code",
        text: "
        const getFifth = (note) => {
            // make our input lower case so we can use 
            // it as a key for our circleOfFifths object
            const lowerCaseNote = note.toLowerCase()
            const circleOfFifths = {
                 c: 'd',
                 g: 'd',
                 d: 'a',
                 a: 'e',
                 e: 'b',
                 b: 'f#',
                 'f#': 'c#',
                 gb: 'db',
                 'c#': 'ab',
                 db: 'ab',
                 ab: 'eb',
                 eb: 'bb',
                 bb:'f',
                 f: 'c'
            }
            // retrieve fifth of our input
            const fifth = circleOfFifths[lowerCaseNote]
            // format the output of the function to always begin with an upercase letter
            const formattedNote = `${fifth.charAt(0).toUpperCase()}${fifth.slice(1)}`
            return formattedNote;
        }
        const fifthOfGb = getFifth('Gb')
        console.log(`The fifth of Gb is ${fifthOfGb}`) // The fifth of Gb is Db"
    }, {
        format: "p",
        text: "
        Write your own function in the file you created. 
        Run the program, in this case: "
    }, {
        format: "code",
        text: "
        node mynewfile.js"
    }, {
        format: "p",
        text: "
        Congratulations! you have written your first function. 

        Tomorrow we will cover making your first Web App."
    },
    ]
}, {    
    id: "1",
    title: "Function Junction, Day 2: Your first Web App.",
    content: [{
        format: "p",
        text: "
        Lets start a real frontend web project.

        Tools you will be adding to your repetoire: 
        >- Git
        >- React
        "
    }, {
        format: "code",
        text: "
        xcode-select --install # install Git, it comes with xcode on macos
        npx create-react-app my-app # Creates an app named my-app
        cd my-app 
        npm start # runs your app"
    }, {
        format: "p",
        text: "
        Now that you have your first app running, lets make a simple app using react hooks.

        Hooks are functions that let you \"hook into\" a components state or lifecycle,
        in this case we can replace the functional component create react app gives us with our own. 
        Ours will have a a hook for count and a button to increment the count. 
        "
    }, {
        format: "code",
        text: "
        import React from 'react';
        import './App.css';
        const { useState } = React
        // We can use an arrow function here as well.
        // In react you create apps from components.
        // These components can be functions as seen below
        // Entire apps can be composed of \"functional components\"
        const App = () => {
            const [count, setCount] = useState(0)
            return (
                <div className=\"App\">
                    <p>{count}</p>
                    <button onClick={() => setCount(count + 1)}>
                        increment count
                    </button> 
                </div>
            );
        }
        export default App;
        "
    }, {
        format: "p",
        text: "
        Here is an example of a react app using hooks that tells you the fifth of any note."
    }, {
        format: "code",
        text: "
        // App.jsx
        import React from 'react';
        import './App.css';
        import{ getFifth } from './getFifth';
        const { useState } = React
        const App = () => {
        const [fifth, setFifth] = useState(0);
        return (
            <div className=\"App\">
            <p>Fifth: {fifth}</p>
            <input onChange={(e) => setFifth(getFifth(e.target.value))}>
            </input>
            </div>
        );
        }
        export default App;

        // getFifth.js
        export const getFifth = (note) => {
            console.log(note)
            if (!note) {
                return '';
            }
            const lowerCaseNote = note.toLowerCase()
            const fifth = {
                c: 'g',
                g: 'd',
                d: 'a',
                a: 'e',
                e: 'b',
                b: 'f#',
                'f#': 'c#',
                gb: 'db',
                'c#': 'ab',
                db: 'ab',
                ab: 'eb',
                eb: 'bb',
                bb: 'f',
                f: 'c'
            }[lowerCaseNote]
            if (!fifth) {
                return '';
            }
            const formattedNote = `${fifth.charAt(0).toUpperCase()}${fifth.slice(1)}`
            return formattedNote
        }
        "
    }, {
        format: "p",
        text: "
        Try to make an app for making a list of groceries, chores, mood-board, or something simple.
        
        *hint <input> can be used for text

        Once you are happy with your app. Lets make sure your code is under version control
        for future updates and collaboration with other developers using Git. 

        First signup or login to Github, https://github.com/. Make a new repository for my-app. 
        "
    }, {
        format: "code",
        text: "
        # cd to your project
        git init # initialize a git repo in your project if you have not already
        # add the remote to your local git repo
        git remote add origin https://github.com/username/my-app 
        # add your code to the staging area
        git add --all
        # commit your changes
        git commit -m\"initial commit\"
        # push your changes to git hub
        git push origin master
        "
    }, {
        format: "p",
        text: "
        Congrats! You developed your first project and put it under source control!
        "
    },]
}, 
/* {
    id: "2",
    title: "Function Junction, Day 3: Your first API",
    content: [{
        format: "p",
        text: "Web apps can only be so interesting without being connectd to a source of data or a place
        to store a users data and interactions with your app. In order to do this we are going to need to 
        create an endpoint where our user will pass data to or ask for data to display. In this post, I'll
        show you two ways to spin up an API endpoint.
        
        Tools we will be adding to your repetoire: 
        >- express (server framework)
        >- serverless (what I use every day)
        "
    }]
} */
]
