# Problem

In our Gitlab projects we often have a triggered [CI/CD pipeline](https://en.wikipedia.org/wiki/CI/CD) when new code is pushed to ensure correctness of the code and manage automatic deployments. These pipelines can have one of three stati:
- PASSED (green)
- RUNNING (blue)
- FAILED (red)

Some pipelines need a really long time to finish. It would be great to have a physical indicator to show the status of a pipeline!

# Possible Solution

Try to create an Arduino setup, that indicates the pipelines status of a specific gitlab project via LEDs (green, blue, red)!

The gitlab project to check it's pipeline: http://gitlab.intranet.centigrade.de/centigrade/trainee-pipeline-tests/-/pipelines

# Hints

Since this projects depends of many working parts you can devide and conquer! Make yourself a plan on how to split up certain parts of the problem and develop / test them individually!

E.g.:
- Develop a function that gets one of the 3 stati as an input and then lights up a specific LED
- Check if you can connect to the internet
- Check if you can connect to the GitlabAPI https://docs.gitlab.com/ee/api/.
There are 2 different kinds of [APIs](https://en.wikipedia.org/wiki/API) available for gitlab. A [REST API](https://en.wikipedia.org/wiki/Representational_state_transfer) and a [GraphQL API](https://en.wikipedia.org/wiki/GraphQL). You might need an external library for the arduino to use APIs, you will have to check that.
- Check if you can request data for the project specified above (You might require an authentication token).

You can write your plan and your evaluation of the problem down. That way it's easier to manage for you in bigger problems and help others understand why you chose certain strategies to tackle the problem.

### GOOD LUCK 🍀