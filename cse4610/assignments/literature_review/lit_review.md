1. Introduction
* Video games are a unique form of multimedia entertainment that require direct interaction from the user.
* Requirements Engineering does not fully understand concepts such as _fun _or _absorbing _as desired within game development.
* This paper seeks to understand and explain the costs of “communication errors” such that the fundament for a formal process in game development may be established.
2. Background
* Requirements Engineering assumes that communication issues for a project with a single disciplinary focus can be resolved in the early stages of development.
* Video game development is a multidisciplinary endeavor for which no work exists to support the assumption made for narrower undertakings.
* The authors performed a literature review to gather knowledge of: emotional factors, issues of domain language, and requirements elicitation and feedback.
    1. Emotions
* Emotional factors in requirements have never been captured officially and no formal elicitation methods exist
* Successful satisfaction of emotional factors in video games can be attributed to the user’s capability to achieve a _flow state _during gameplay.
    2. Language
* Definition of the domain in requirements engineering equates to translating informal language into an unambiguous specification
* Game designers work with members of the production team to write natural language requirements that may later see formalization during development.
    3. Elicitation and Feedback
* Feedback from development staff to conceptual staff can elicit emergent requirements prior to the transition from preproduction to production phases.
3. Game Development
* For every advertisement of an upcoming video game, a large number of projects being worked on in the same timeframe have failed.
* “The multidisciplinary nature of the video game development process… may recommend a specialized software engineering methodology for this domain.” [pg 3]
    4. Process
* The video game development process is modeled as a diagram showing that preproduction leads consecutively into production.
* The transition from preproduction to production of a video game is highly difficult as implications and explicit details must be reconciled in the translation of the Game Design Document into a specification.
    5. Design Document
* The Game Design Document (GDD) is the creative brainstorming document that acts as the “requirements document” for the preproduction team.
* The GDD varies widely across genres of games, and usually includes “a concept statement and tagline, the genre of the game, the story behind the game, the characters within the game, and the character dialogue.” [pg 3]
* The documentation of the preproduction and production processes in game development vary greatly in structure, and parallel maintenance of both is extremely challenging because no standard practices exist.
4. Preproduction vs. Production
* Requirements errors are some of the most costly to fix; errors of this type can cost up to 100 times more to fix after delivery than if caught at the start of the project. Many projects still suffer from failures due to inadequate requirements engineering. 
* Projects could remain in preproduction for longer (normally too short) to reduce surprises and develop intermediary documentation that is more formal and structure than the normal informal manner this switch is conducted under. 
* Despite the fact that this change occurs in every game, there is no document strategy to go through this process. The existing processes are likely kept by the company's management and not publicly released, but insiders say the transition rarely goes well (“I have never seen a completed design document.”).  
5. Postmortem Columns
* While the management processes for various companies are corporate secrets, the Postmortem columns provide insight into the process by allowing developers to share 5 features/aspects that went off better than planned and 5 that didn’t. These written pieces are usually perceived to be factual and written by management on the project. 
* The classifications scheme has five categories: 
    * (1) preproduction, issues outside of the traditional software development process such as inadequate game design or inadequate storyboarding,
    * (2) internal, issues related to project management and personnel 
    * (3) external, issues outside of the control of the development team such as changes in the marketplace and financial conditions 
    * (4) technology, issues related to the creation or adoption of new technologies
    * (5) schedule, issues related to time estimates and overruns. Schedule issues are a subset of internal issues, but were uniquely identified in an effort to determine if scheduling was a significant issue. 
    * Any pair of the five categories was also possible (e.g., “internal and technology”) if the entry was that precise.
* Figure #2
    * Only factors that represent more than 10% of final results are shown. 
    * Internal factors dominate any other category by a factor of approximately 300%.
    * PM4W52 notes “inadequate planning, 
    * PM20W3 claims a lack of success due to “underestimating the scope of tasks 
    * PM9W3 calls their schedule “too aggressive, 
    * PM18W2 states that “clear goals are great when they are realistic and 
    * PM21W1 states that “an unrealistic schedule can’t be saved without pain. 
    * It appears that these issues could be addressed by a RE process that better manages the transition from preproduction to production.
    * Interestingly, across all categories taking into account every project in these Postmortems, the max deviation between it going right and wrong was only 7.7%. 
* Figure #3
    * Within a given project, any of the main categories could equally lead to success or failure.
6. Examples from Real Games
* Let's look at real games that are currently in development or have been released. The big three topics that will be discussed are documentation transformation, implication creating emergent requirements, and the effects of a priori knowledge.
    6. Documentation
* Table #1
    * The game designer begins (1) with a story written in a narrative style.
    * That story is then translated (elsewhere in the game design document) to a more formal form (2) that describes the action as a task and a justification for that task.
    * The requirements engineer analyzes this information, in context (3), to determine a set of requirements: identifying in-game assets such as the player avatar, Anna (a Non-Player Character (NPC)) and an inventory item. A state that controls the player's progress through the game is also identified and captured. 
    * Depending on the in-house process used, the detailed description (4) of these in-game assets may be part of the requirements document or part of a specification document. Independent of where the detailed descriptions are located, they could easily reach 50 pages once issues like artistic style, animation, and game state are included.
* Managing this transformation and flow is challenging due to the numerous writing styles required and depths of knowledge required to make the writing make sense. This list of required skills is large and requires a team to be done properly, increasing the cost of proper transitiatory documentation. Hence, to keep costs down this team is normally smaller to minimize the cost of documentation. 
    7. Implication
* Due to the idea of ‘creative works’ like video games are, the design documents are littered with implied information and assumptions. To find these implied pieces, it requires significant domain knowledge and careful analysis. 
* First Level Implications: the previous table (Table #1) shows implications that can be derived directly from the materials presented to the team. 
* Second Level Implications: these implications require knowledge of the general domain. This could be things like the game genre (RPG, MMO, etc). These implications are normally around things like the game world/environment. Are there other players in the area, can the NPCs interact with you, what does the current place look like. 
* Third Level Implications: These implications revolve around the target architecture, game engine, and controls. This is handled by an experienced team that can describe the needs of deploying to a specific hardware platform, game engine needs and features, and player interaction with the controls, movement, and world. Things like a stateful game, can make this significantly more complicated with the game needing to remember previous decisions by the character and reacting to them. 
* An iterative process can be used to dive through these levels of implications. Early feedback might seem great but creative teams and developers may think ideas are too much and negative feedback may limit the team. The effects of early feedback should be investigated further to see if these is a better process. 
    8. _A priori _Knowledge
* Knowing the nuances of game design is important for iterating on games. When this is lacking, the requirements of a game being developed, and documenting these is a big challenge. Because of this, the insights often needed from the design process to continue work on the game are obscured because of the quick and competitive environment of the video game industry. This need for _a priori_ knowledge and the speed at which games are developed cause compromises to be made, often to the detriment of the creative process.
    9. Evaluation
* As game designers iterate on an idea for a puzzle or feature while accommodating the business side of the industry, often lack of scheduling time for creative tasks will lead to an idea demanding more than the underlying technology can deliver. This balance between creativity and production business brings variety to Requirements Engineering.
7. Summary/Conclusions
* Project management is one of the biggest challenges for video game development, often being the cause of success or failure. Lack of requirements engineering in preproduction are the biggest contributor to the loss of cohesive vision for the project.
* Three Levels of Implication: implications derived directly from materials, those derived from introductory general knowledge of a domain, and implications only derived from implementation details, like target architecture.
8. Challenges for Req. Eng.
* Issues in the video game industry applicable to Requirements Engineering include:
    * Communication between stakeholders of disparate background
    * Consistent focus of goals and resisting feature creep
    * Influence of prior work
    * Media/Technology interaction and integration
    * Importance of non-functional requirements
    * Gameplay requirements
    10. Media and Tech
* Ensuring a production pipeline that accommodates both technical and artistic members of the team is vital, often either making or breaking a project’s development.
* Deciding the minimum target requirements for a system to run the game allows the limitations to be clear to all members of the development team.
    11. Non-func. Reqs.
* NFRs is a larger part of video games because their primary purpose is to be a form of entertainment. Thus, validation of NFRs in games is very important, yet can be extremely tedious.
    12. Gameplay
* Functional and well tested gameplay elements are very important to a game’s success, and can be overlooked when considering NFRs. Problems with gameplay can cause a player to be removed from the immersion of the world being presented when they can clip through the floor or use a horse to walk up a mountain’s sheer cliff face.
9. Future Work
* Analyzing other reports from Game Developer magazine should help guide the process of Req Eng in the games industry, specifically with respect to the transition between preproduction and production. Finding ways to quantify NFRs, such as fun, is also a part of the process that needs ways to be measured and verified.