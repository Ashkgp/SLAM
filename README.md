##Probabilistic Approach of bot Localisation

Code takes in account the errors in measurement of the exact positions of the bots by the on board camera and error in movement of bots due to varying speeds or other external factors.

Bot position is modeled as a gaussian with mean as the recorded position or velocity and variance as the error or probability the bot actually being at that point.

Kalman filter is used to predict the position of bots and it is constantly being updated.

If the quad sees a bot it's gaussian curve becomes steeper and variance reduces as quad then has better knowledge about that bot's position where as not seeing bot for long times decreases the pobability of bot being at the expected point by the Kalman filter due to addition of variance in recorded position and uncertainity in the velocity of bot added over time.

