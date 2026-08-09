using SoulConnect.Services;
using System.Linq;
using System.Threading.Tasks;

namespace SoulConnect.Models
{
    public static class AstroCompatibility
    {
        public static string CalculateCompatibility(string sign1, string sign2)
        {
            switch (sign1)
            {
                case "Aries":
                    switch (sign2)
                    {
                        case "Aries":
                            return "High Compatibility - Both Aries share dynamic energy!";
                        case "Taurus":
                            return "Low Compatibility - Aries' impulsive nature clashes with Taurus' patience.";
                        case "Gemini":
                            return "High Compatibility - Aries and Gemini can have exciting and adventurous relationships.";
                        case "Cancer":
                            return "Low Compatibility - Aries may find Cancer too emotional.";
                        case "Leo":
                            return "High Compatibility - Aries and Leo are both passionate and driven.";
                        case "Virgo":
                            return "Low Compatibility - Virgo's attention to detail might annoy Aries.";
                        case "Libra":
                            return "Moderate Compatibility - Aries and Libra may balance each other out.";
                        case "Scorpio":
                            return "Moderate Compatibility - Aries and Scorpio can have a strong connection, but might fight for control.";
                        case "Sagittarius":
                            return "High Compatibility - Aries and Sagittarius both love adventure and freedom.";
                        case "Capricorn":
                            return "Low Compatibility - Capricorn's discipline may clash with Aries' impulsiveness.";
                        case "Aquarius":
                            return "High Compatibility - Both love independence and innovation.";
                        case "Pisces":
                            return "Low Compatibility - Aries may find Pisces too sensitive.";
                    }
                    break;

                case "Taurus":
                    switch (sign2)
                    {
                        case "Aries":
                            return "Low Compatibility - Taurus' stability contrasts with Aries' fiery nature.";
                        case "Taurus":
                            return "Moderate Compatibility - Both value stability, but might struggle with stubbornness.";
                        case "Gemini":
                            return "Low Compatibility - Taurus may find Gemini's flightiness unsettling.";
                        case "Cancer":
                            return "High Compatibility - Taurus and Cancer both value security and family.";
                        case "Leo":
                            return "Low Compatibility - Leo's boldness might be too much for Taurus' need for routine.";
                        case "Virgo":
                            return "High Compatibility - Taurus and Virgo are practical and grounded.";
                        case "Libra":
                            return "Moderate Compatibility - Taurus and Libra both love beauty, but Libra's indecision might frustrate Taurus.";
                        case "Scorpio":
                            return "High Compatibility - Taurus and Scorpio can have a passionate, intense relationship.";
                        case "Sagittarius":
                            return "Low Compatibility - Taurus' need for stability may conflict with Sagittarius' desire for freedom.";
                        case "Capricorn":
                            return "High Compatibility - Taurus and Capricorn are both practical and hardworking.";
                        case "Aquarius":
                            return "Low Compatibility - Taurus' traditional ways might clash with Aquarius' unconventional approach.";
                        case "Pisces":
                            return "High Compatibility - Taurus and Pisces share a love of beauty and comfort.";
                    }
                    break;

                case "Gemini":
                    switch (sign2)
                    {
                        case "Aries":
                            return "High Compatibility - Gemini loves Aries' spontaneity and excitement.";
                        case "Taurus":
                            return "Low Compatibility - Gemini's curiosity can conflict with Taurus' need for routine.";
                        case "Gemini":
                            return "Moderate Compatibility - Both are intellectually stimulating but might struggle with stability.";
                        case "Cancer":
                            return "Low Compatibility - Gemini might find Cancer too clingy.";
                        case "Leo":
                            return "High Compatibility - Gemini and Leo share a love of fun and creativity.";
                        case "Virgo":
                            return "Moderate Compatibility - Both are ruled by Mercury, but Virgo's practicality may bore Gemini.";
                        case "Libra":
                            return "High Compatibility - Gemini and Libra both enjoy intellectual conversation and socializing.";
                        case "Scorpio":
                            return "Low Compatibility - Gemini might find Scorpio too intense.";
                        case "Sagittarius":
                            return "High Compatibility - Opposites attract with Gemini and Sagittarius, both love adventure.";
                        case "Capricorn":
                            return "Low Compatibility - Capricorn's discipline might stifle Gemini's free spirit.";
                        case "Aquarius":
                            return "High Compatibility - Both are intellectual and love new ideas.";
                        case "Pisces":
                            return "Low Compatibility - Gemini might find Pisces' emotional depth hard to handle.";
                    }
                    break;

                case "Cancer":
                    switch (sign2)
                    {
                        case "Aries":
                            return "Low Compatibility - Cancer may find Aries too brash and insensitive.";
                        case "Taurus":
                            return "High Compatibility - Both value security and emotional depth.";
                        case "Gemini":
                            return "Low Compatibility - Gemini might be too detached for Cancer's emotional needs.";
                        case "Cancer":
                            return "High Compatibility - Two Cancers can create a deeply nurturing relationship.";
                        case "Leo":
                            return "Moderate Compatibility - Leo's outgoing nature can complement Cancer's nurturing instincts.";
                        case "Virgo":
                            return "High Compatibility - Cancer and Virgo both value stability and care.";
                        case "Libra":
                            return "Low Compatibility - Libra's indecision might frustrate Cancer.";
                        case "Scorpio":
                            return "High Compatibility - Both are emotional and passionate signs.";
                        case "Sagittarius":
                            return "Low Compatibility - Sagittarius' love of freedom might conflict with Cancer's need for security.";
                        case "Capricorn":
                            return "Moderate Compatibility - Opposites attract with Cancer's emotions and Capricorn's practicality.";
                        case "Aquarius":
                            return "Low Compatibility - Aquarius' aloof nature might clash with Cancer's sensitivity.";
                        case "Pisces":
                            return "High Compatibility - Both are emotional and intuitive signs.";
                    }
                    break;

                case "Leo":
                    switch (sign2)
                    {
                        case "Aries":
                            return "High Compatibility - Both are passionate, driven, and full of energy.";
                        case "Taurus":
                            return "Low Compatibility - Taurus' stubbornness might clash with Leo's need for attention.";
                        case "Gemini":
                            return "High Compatibility - Leo and Gemini share a love of fun and adventure.";
                        case "Cancer":
                            return "Moderate Compatibility - Leo's boldness can complement Cancer's nurturing nature.";
                        case "Leo":
                            return "High Compatibility - Both Leos enjoy admiration and share similar energies.";
                        case "Virgo":
                            return "Low Compatibility - Virgo's critical nature may conflict with Leo's need for appreciation.";
                        case "Libra":
                            return "High Compatibility - Leo and Libra can create a balanced and harmonious relationship.";
                        case "Scorpio":
                            return "Low Compatibility - Both strong-willed, they may clash for control.";
                        case "Sagittarius":
                            return "High Compatibility - Leo and Sagittarius share enthusiasm and optimism.";
                        case "Capricorn":
                            return "Low Compatibility - Leo's love for the spotlight might clash with Capricorn's reserved nature.";
                        case "Aquarius":
                            return "Moderate Compatibility - Opposites attract, but conflicts may arise.";
                        case "Pisces":
                            return "Low Compatibility - Leo might overwhelm sensitive Pisces.";
                    }
                    break;

                case "Virgo":
                    switch (sign2)
                    {
                        case "Aries":
                            return "Low Compatibility - Virgo's need for order might frustrate Aries' impulsive nature.";
                        case "Taurus":
                            return "High Compatibility - Virgo and Taurus share practicality and groundedness.";
                        case "Gemini":
                            return "Moderate Compatibility - Virgo may find Gemini's curiosity refreshing but tiring.";
                        case "Cancer":
                            return "High Compatibility - Both value emotional and material security.";
                        case "Leo":
                            return "Low Compatibility - Virgo's reserved nature can clash with Leo's need for attention.";
                        case "Virgo":
                            return "High Compatibility - Two Virgos can have a harmonious relationship with shared values.";
                        case "Libra":
                            return "Moderate Compatibility - Virgo's practicality may contrast with Libra's idealism.";
                        case "Scorpio":
                            return "High Compatibility - Virgo and Scorpio can share a deep intellectual bond.";
                        case "Sagittarius":
                            return "Low Compatibility - Sagittarius' adventurous spirit may clash with Virgo's need for routine.";
                        case "Capricorn":
                            return "High Compatibility - Both are hardworking, practical signs.";
                        case "Aquarius":
                            return "Low Compatibility - Virgo's need for order might not mesh with Aquarius' free-spirited approach.";
                        case "Pisces":
                            return "Moderate Compatibility - Opposites attract, but they may struggle to find common ground.";
                    }
                    break;

                case "Libra":
                    switch (sign2)
                    {
                        case "Aries":
                            return "Moderate Compatibility - Opposites attract with Aries' assertiveness and Libra's charm.";
                        case "Taurus":
                            return "Moderate Compatibility - Libra's indecision may frustrate Taurus' steadiness.";
                        case "Gemini":
                            return "High Compatibility - Both are air signs and love socializing and intellectual pursuits.";
                        case "Cancer":
                            return "Low Compatibility - Libra's detachment may clash with Cancer's emotional depth.";
                        case "Leo":
                            return "High Compatibility - Both enjoy a harmonious and romantic relationship.";
                        case "Virgo":
                            return "Moderate Compatibility - Virgo's practicality may contrast with Libra's idealism.";
                        case "Libra":
                            return "High Compatibility - Two Libras can have a balanced and harmonious relationship.";
                        case "Scorpio":
                            return "Low Compatibility - Scorpio's intensity might overwhelm Libra's need for harmony.";
                        case "Sagittarius":
                            return "High Compatibility - Both enjoy fun and adventure in life and relationships.";
                        case "Capricorn":
                            return "Low Compatibility - Libra's free-spirited nature might conflict with Capricorn's seriousness.";
                        case "Aquarius":
                            return "High Compatibility - Both enjoy intellectual conversations and shared social pursuits.";
                        case "Pisces":
                            return "Moderate Compatibility - Libra's indecision may frustrate Pisces' emotional nature.";
                    }
                    break;

                case "Scorpio":
                    switch (sign2)
                    {
                        case "Aries":
                            return "Moderate Compatibility - Both are passionate, but may fight for control.";
                        case "Taurus":
                            return "High Compatibility - Scorpio and Taurus can have a deep, intense bond.";
                        case "Gemini":
                            return "Low Compatibility - Gemini's flighty nature may conflict with Scorpio's intensity.";
                        case "Cancer":
                            return "High Compatibility - Both are emotional and intuitive signs with a strong bond.";
                        case "Leo":
                            return "Low Compatibility - Both strong-willed, they may clash for control.";
                        case "Virgo":
                            return "High Compatibility - Virgo and Scorpio share deep intellectual and emotional connections.";
                        case "Libra":
                            return "Low Compatibility - Scorpio's intensity may overwhelm Libra's need for harmony.";
                        case "Scorpio":
                            return "High Compatibility - Two Scorpios can have an intense and passionate relationship.";
                        case "Sagittarius":
                            return "Low Compatibility - Scorpio's depth may conflict with Sagittarius' carefree nature.";
                        case "Capricorn":
                            return "High Compatibility - Both are ambitious and deeply committed.";
                        case "Aquarius":
                            return "Low Compatibility - Scorpio may find Aquarius too detached and unemotional.";
                        case "Pisces":
                            return "High Compatibility - Both are water signs with deep emotional connections.";
                    }
                    break;

                case "Sagittarius":
                    switch (sign2)
                    {
                        case "Aries":
                            return "High Compatibility - Both signs love adventure and spontaneity.";
                        case "Taurus":
                            return "Low Compatibility - Sagittarius' need for freedom may conflict with Taurus' stability.";
                        case "Gemini":
                            return "High Compatibility - Both love adventure and intellectual pursuits.";
                        case "Cancer":
                            return "Low Compatibility - Sagittarius' free-spirited nature may clash with Cancer's emotional needs.";
                        case "Leo":
                            return "High Compatibility - Both are energetic and adventurous.";
                        case "Virgo":
                            return "Low Compatibility - Sagittarius may find Virgo too detail-oriented.";
                        case "Libra":
                            return "High Compatibility - Both love fun, adventure, and socializing.";
                        case "Scorpio":
                            return "Low Compatibility - Sagittarius' carefree nature may clash with Scorpio's intensity.";
                        case "Sagittarius":
                            return "High Compatibility - Both share a love for freedom and adventure.";
                        case "Capricorn":
                            return "Low Compatibility - Sagittarius may find Capricorn too serious and restrictive.";
                        case "Aquarius":
                            return "High Compatibility - Both enjoy freedom and intellectual pursuits.";
                        case "Pisces":
                            return "Moderate Compatibility - Sagittarius' carefree nature may overwhelm sensitive Pisces.";
                    }
                    break;

                case "Capricorn":
                    switch (sign2)
                    {
                        case "Aries":
                            return "Low Compatibility - Capricorn's discipline may clash with Aries' impulsiveness.";
                        case "Taurus":
                            return "High Compatibility - Both are practical, hardworking, and value stability.";
                        case "Gemini":
                            return "Low Compatibility - Capricorn may find Gemini too flighty and undisciplined.";
                        case "Cancer":
                            return "Moderate Compatibility - Opposites attract with Cancer's emotions and Capricorn's practicality.";
                        case "Leo":
                            return "Low Compatibility - Capricorn may find Leo too self-centered and extravagant.";
                        case "Virgo":
                            return "High Compatibility - Both value hard work, stability, and pragmatism.";
                        case "Libra":
                            return "Low Compatibility - Capricorn's seriousness may conflict with Libra's need for harmony and fun.";
                        case "Scorpio":
                            return "High Compatibility - Both are determined and driven, with a deep connection.";
                        case "Sagittarius":
                            return "Low Compatibility - Sagittarius' free spirit may clash with Capricorn's need for order.";
                        case "Capricorn":
                            return "High Compatibility - Two Capricorns will build a solid, disciplined relationship.";
                        case "Aquarius":
                            return "Low Compatibility - Capricorn may find Aquarius too unconventional and free-spirited.";
                        case "Pisces":
                            return "Moderate Compatibility - Capricorn's practicality can ground Pisces' dreaminess, but may lack emotional connection.";
                    }
                    break;

                case "Aquarius":
                    switch (sign2)
                    {
                        case "Aries":
                            return "High Compatibility - Both are adventurous, independent, and love freedom.";
                        case "Taurus":
                            return "Low Compatibility - Aquarius may find Taurus too traditional and slow-moving.";
                        case "Gemini":
                            return "High Compatibility - Both are intellectual and curious about the world.";
                        case "Cancer":
                            return "Low Compatibility - Aquarius' detachment may clash with Cancer's emotional depth.";
                        case "Leo":
                            return "Moderate Compatibility - Opposites attract, but may struggle to understand each other's needs.";
                        case "Virgo":
                            return "Low Compatibility - Aquarius' free-spirited nature may conflict with Virgo's need for order.";
                        case "Libra":
                            return "High Compatibility - Both love intellectual conversations and shared social pursuits.";
                        case "Scorpio":
                            return "Low Compatibility - Aquarius may find Scorpio too intense and controlling.";
                        case "Sagittarius":
                            return "High Compatibility - Both love freedom and intellectual conversations.";
                        case "Capricorn":
                            return "Low Compatibility - Aquarius' unconventional nature may clash with Capricorn's pragmatism.";
                        case "Aquarius":
                            return "High Compatibility - Both share a love for freedom, innovation, and intellectual pursuits.";
                        case "Pisces":
                            return "Moderate Compatibility - Aquarius' detachment may overwhelm Pisces' emotional needs.";
                    }
                    break;

                case "Pisces":
                    switch (sign2)
                    {
                        case "Aries":
                            return "Low Compatibility - Aries' directness may overwhelm sensitive Pisces.";
                        case "Taurus":
                            return "High Compatibility - Pisces and Taurus share a love for beauty, comfort, and emotional depth.";
                        case "Gemini":
                            return "Low Compatibility - Pisces may find Gemini's flighty nature difficult to handle.";
                        case "Cancer":
                            return "High Compatibility - Both are emotional and intuitive signs with deep bonds.";
                        case "Leo":
                            return "Low Compatibility - Pisces may find Leo too overwhelming and self-centered.";
                        case "Virgo":
                            return "Moderate Compatibility - Opposites attract, but they may struggle to find common ground.";
                        case "Libra":
                            return "Moderate Compatibility - Libra's indecision may frustrate Pisces' emotional nature.";
                        case "Scorpio":
                            return "High Compatibility - Both are emotional and passionate, with a deep connection.";
                        case "Sagittarius":
                            return "Moderate Compatibility - Sagittarius' carefree nature may overwhelm sensitive Pisces.";
                        case "Capricorn":
                            return "Moderate Compatibility - Capricorn's practicality can ground Pisces' dreaminess, but may lack emotional connection.";
                        case "Aquarius":
                            return "Moderate Compatibility - Aquarius' detachment may overwhelm Pisces' emotional needs.";
                        case "Pisces":
                            return "High Compatibility - Two Pisces can create a deeply emotional and spiritual bond.";
                    }
                    break;

                default:
                    return "Unknown Compatibility - Please enter valid signs.";
            }

            return "Unknown Compatibility - No specific compatibility information found for these signs.";
        }
    }
}