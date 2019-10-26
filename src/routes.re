type post = {
    id: string,
    title: string,
    content: string,
  };
let posts =  [{
    id: "0",
    title: "Reasons to start a (programming) project",
    content: "There are lots of reasons not to start a project. Here are a few of my mental roadblocks.

1. The project has already been started by someone else, possibly reinventing the wheel.
2. You may have to learn a new tech stack.
3. Imposter syndrome, who are you to start a blog?
4. Optional paralysis, too many design decisions.

Lets start with roadblock 1. Take this blog engine for example. I was tempted to use an already well made blog engine. There is Gatsby, Ghost, Hugo, and many others. Why would I want to make my own? For my needs, these all seemed too bloated and relied heavily on other libraries or they were created with technologies that were too familiar or that I am not eager to get into, as of now. I wanted to start writing reasonml and I figured this would be a good first project to get into. I can keep the dependencies low, just webpack and reason-react. I don't need a server to run my code, and I can just use a static file for all my posts. I also am working on a small CLI to make blogging with this engine easier than editing json.
    
Reason 2, At work this Friday we had a hackathon. We decided to work on AR stages for music festivals (think face filters but for a concert stage). This required me to get in the weeds with Tensorflow to create a model for concert stages. I haven't really used tensorflow in a year and the retraining MobileSSD model was a harder task than I thought it would be. The results of this were not being able to get a finished product in time for the 5pm deadline. Looking back, my goal was too ambitious. Learning an unfamiliar technology stack can be a huge block. However, I think I ended up learning more than if I had built a functioning product. I learned the importance of project management as well as some cool machine learning features in the Google Cloud. I think I have a better idea of where I would start given the same problem. 
    
Reason 3, why should I have a blog or write a blog engine? I often feel insignificant in the face of peoples ever growing git stats on Github, I have not contributed a lot to open soure, and I work a 9-5. The only thing I can think of is that I just like to make things and you all may just have to deal with it.

Reason 4, there are a million ways to do something and endless libraries to explore. Finding the right tool can often take longer than creating the product. There are lots of libraries that enhance maintainability and efficency like Apollo GraphQL and Redux for Javascript. However, if these become roadblocks to getting started, say you have never made a react app before, I would suggest instead you try to go much more vanilla before you add toppings.  
"
}
]
// let posts =  [{
//                 id: "0",
//                 title: "thebestREST",
//                 content: "It's GraphQL"
//             },
//             {
//                 id: "1",
//                 title: "3D, ASCII, and Me",
//                 content: "Three JS with love"
//             },
//             {
//                 id: "2",
//                 title: "Jargon Schmargon",
//                 content: "Lets talk about our jargon as a barrier to entry."
//             },
//             {
//                 id: "3",
//                 title: "Brewing Kombucha (and how to scare your mom)",
//                 content: ""
//             },
//             {
//                 id: "4",
//                 title: "Bike repair for a non bike mechanic",
//                 content: ""
//             }
//         ]