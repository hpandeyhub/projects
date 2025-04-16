import streamlit as st

from streamlit_option_menu import option_menu
st.set_page_config(
    page_title='RE-cOMMENDER-system',
    page_icon="12",
)
st.sidebar.success('select ')
st.title("home page")

st.write(':balloon: we welcome you to our recommender system which recommend you books and movies based on your search this recommender system is developed my himanshu cube:balloon:')

def star_rating(rating):
    full_star = "★"
    empty_star = "☆"
    return full_star * int(rating) + empty_star * (5 - int(rating))


# Create a slider for rating
user_rating = st.slider('Rate this:', 3, 5, key='slider')

# Display the rating in the form of stars
st.markdown('You rated: {}'.format(user_rating), unsafe_allow_html=True)

# Inject JavaScript to prevent the default behavior of the slider
st.markdown(
    """
    <script>
        var slider = document.querySelector('[data-baseweb="slider"]');
        slider.addEventListener('pointerup', function(event) {
            event.preventDefault();
        });
    </script>
    """,
    unsafe_allow_html=True
)